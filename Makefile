build: init transpile build-java build-dotnet build-c \
build-python build-go build-ts

OTTEROP_VERSION=0.2.0
OTTEROP_VERSION_LOCAL=master
BLUE=\033[0;34m
RESET_COLOR=\e[0m

.PHONY: configure-local configure-published init init-submodules otterop transpile \
build-java build-python build-c build-ts \
build-dotnet build-go clean

init: init-submodules otterop

otterop:
	@make -C otterop

init-submodules:
	@git submodule update --init --recursive

check-submodules:
	@if git submodule status | grep --quiet '^-'; then \
		echo "A git submodule is not initialized." && exit 1; \
	fi

configure-local:
	@echo "$(BLUE)Configuring with local OtterOP ...${RESET_COLOR}"
	@(export OTTEROP_VERSION=$(OTTEROP_VERSION) && \
	export OTTEROP_DEPENDENCIES=local && \
	(cd otterop && git checkout $(OTTEROP_VERSION_LOCAL) && \
	git pull) && \
	(cd python && . ./_venv/bin/activate && \
	. ./install.local.sh) && \
	./gradle.properties.tpl > ./gradle.properties && \
	./settings.gradle.kts.tpl > ./settings.gradle.kts && \
	./dotnet/src/Sort.csproj.tpl > ./dotnet/src/Sort.csproj && \
	./dotnet/tests/Sort.Tests.csproj.tpl > ./dotnet/tests/Sort.Tests.csproj && \
	./go/go.mod.tpl > ./go/go.mod && \
	./ts/package.json.tpl > ./ts/package.json) > /dev/null

configure-published:
	@echo "$(BLUE)Configuring with published OtterOP ...${RESET_COLOR}"
	@(export OTTEROP_VERSION=$(OTTEROP_VERSION) && \
	export OTTEROP_DEPENDENCIES=published && \
	(cd otterop && git checkout tags/v$(OTTEROP_VERSION)) && \
	(cd python && . ./_venv/bin/activate && \
	. ./install.published.sh) && \
	./gradle.properties.tpl > ./gradle.properties && \
	./settings.gradle.kts.tpl > ./settings.gradle.kts && \
	./dotnet/src/Sort.csproj.tpl > ./dotnet/src/Sort.csproj && \
	./dotnet/tests/Sort.Tests.csproj.tpl > ./dotnet/tests/Sort.Tests.csproj && \
	./go/go.mod.tpl > ./go/go.mod && \
	./ts/package.json.tpl > ./ts/package.json) > /dev/null

transpile: build-java
	@echo "$(BLUE)Transpile Java ...${RESET_COLOR}"
	@java -cp otterop/java/transpiler/build/libs/transpiler-$(OTTEROP_VERSION).jar:otterop/java/lang/build/libs/lang-$(OTTEROP_VERSION).jar:otterop/java/io/build/libs/io-$(OTTEROP_VERSION).jar:otterop/java/test/build/libs/test-$(OTTEROP_VERSION).jar:build/classes/java/main:build/classes/java/test otterop.transpiler.Otterop config/oopconfig.yml

build-java:
	@echo "$(BLUE)Build Java ...${RESET_COLOR}"
	@./gradlew jar > /dev/null
	@echo "$(BLUE)Test Java ...${RESET_COLOR}"
	@./gradlew test

build-python:
	@echo "$(BLUE)Build Python ...${RESET_COLOR}"
	@(cd python && \
	if [ ! -d _venv ]; then \
	python -m venv _venv; \
	fi && \
	. ./_venv/bin/activate && \
	python -m pip install ../otterop/python/lang ../otterop/python/test && \
	python -m pip install .[tests] ) > /dev/null
	@echo "$(BLUE)Test Python ...${RESET_COLOR}"
	@(cd python && \
	. ./_venv/bin/activate && \
	pytest)

build-c:
	@echo "$(BLUE)Build C ...${RESET_COLOR}"
	@(cd c && \
	cmake . && \
	make) > /dev/null
	@echo "$(BLUE)Test C ...${RESET_COLOR}"
	@(cd c && \
	make test)

build-ts:
	@echo "$(BLUE)Build TypeScript ...${RESET_COLOR}"
	@(cd ts && \
	rm -rf node_modules && \
	pnpm i && \
	pnpm build) > /dev/null
	@echo "$(BLUE)Test TypeScript ...${RESET_COLOR}"
	@(cd ts && \
	pnpm test)

build-dotnet:
	@echo "$(BLUE)Build .NET ...${RESET_COLOR}"
	@(cd dotnet && \
	dotnet build) > /dev/null
	@echo "$(BLUE)Test .NET ...${RESET_COLOR}"
	@(cd dotnet && \
	dotnet test)

build-go:
	@echo "$(BLUE)Build Go ...${RESET_COLOR}"
	@(cd go/example/sort && \
	go build) > /dev/null
	@echo "$(BLUE)Test Go ...${RESET_COLOR}"
	@(cd go/example/sort && \
	go test ./...)

clean: check-submodules
	@echo "$(BLUE)Cleaning ...${RESET_COLOR}"
	@(rm -rf ./python/_venv \
	ts/node_modules \
	./c/CMakeCache.txt && \
	./gradlew clean && \
	make -C otterop clean) > /dev/null


build: otterop transpile build-java build-dotnet build-c \
build-python build-go build-ts

VERSION=0.2.0-SNAPSHOT

.PHONY: otterop init-submodules transpile \
build-java build-python build-c build-ts \
build-dotnet build-go clean

init-submodules:
	@git submodule update --init --recursive

otterop: init-submodules
	@echo "Install OtterOP Java libraries ..."
	@(cd otterop/java && \
	./gradlew build publishToMavenLocal :transpiler:jar) > /dev/null

transpile: otterop build-java
	@echo "Transpile Java example ..."
	@java -cp otterop/java/transpiler/build/libs/transpiler-$(VERSION).jar:$$HOME/.m2/repository/otterop/lang/$(VERSION)/lang-$(VERSION).jar:$$HOME/.m2/repository/otterop/io/$(VERSION)/io-$(VERSION).jar:build/libs/otterop-example-sort.jar otterop.transpiler.Otterop src/main/java

build-java:
	@echo "Build Java example ..."
	@./gradlew jar > /dev/null

build-python:
	@echo "Build Python example ..."
	@(cd python && \
	python -m venv _venv && \
	. ./_venv/bin/activate && \
	python -m pip install .) > /dev/null

build-c:
	@echo "Build C example ..."
	@(cd c && \
	cmake . && \
	make) > /dev/null

build-ts:
	@echo "Build TypeScript example ..."
	@(cd ts && \
	rm -rf node_modules && \
	npm ci && \
	npm run build) > /dev/null

build-dotnet:
	@echo "Build .NET example ..."
	@(cd dotnet && \
	dotnet build) > /dev/null

build-go:
	@echo "Build Go example ..."
	@(cd go/example/sort/sort && \
	go build) > /dev/null

clean: init-submodules
	@echo "Cleaning ..."
	@(rm -rf ./python/_venv \
	ts/node_modules && \
	rm -rf ./c/CMakeCache.txt && \
	rm -rf dotnet/Example ./c/example go/example python/example ts/example && \
	./gradlew clean && \
	cd otterop/java && ./gradlew clean) > /dev/null


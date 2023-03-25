#!/bin/sh
set -e
echo "Run Java ..."
(java -jar build/libs/otterop-example-sort.jar $@)
echo "Run .NET ..."
(cd dotnet && ./bin/Debug/*/Sort $@)
echo "Run C ..."
(cd c && ./out/bin/example_sort $@)
echo "Run Python ..."
(cd python && . _venv/bin/activate && python -m example.sort.sort $@)
echo "Run Go ..."
(./go/example/sort/sort/sort $@)
echo "Run JS ..."
(cd ts && node example/sort/Sort.js $@)
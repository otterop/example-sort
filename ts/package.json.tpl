#!/bin/sh
cat <<'EOF'
{
  "name": "example_program",
  "version": "0.1.0",
  "description": "Otterop example program",
  "main": "program.js",
  "scripts": {
    "test": "jest",
    "build": "tsc -p ."
  },
  "keywords": [
    "otterop",
    "example"
  ],
  "author": "Emanuele Sabellico",
  "license": "BSD-2-Clause",
  "devDependencies": {
EOF
if [ "$OTTEROP_DEPENDENCIES" = "local" ]; then
cat <<'EOF'
    "@otterop/test": "file:../otterop/ts/test",
EOF
else
cat <<'EOF'
    "@otterop/test": "^0.2.0",
EOF
fi
cat <<'EOF'
    "@types/jest": "^29.5.11",
    "@types/node": "^18.19.4",
    "jest": "^29.7.0",
    "typescript": "^5.3.3"
  },
  "dependencies": {
EOF
if [ "$OTTEROP_DEPENDENCIES" = "local" ]; then
cat <<'EOF'
    "@otterop/io": "file:../otterop/ts/io",
    "@otterop/lang": "file:../otterop/ts/lang"
EOF
else
cat <<EOF
    "@otterop/io": "^$OTTEROP_VERSION",
    "@otterop/lang": "^$OTTEROP_VERSION"
EOF
fi
cat <<'EOF'
  }
}
EOF







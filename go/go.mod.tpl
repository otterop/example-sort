#!/bin/sh
cat <<'EOF'
module github.com/otterop/example-sort/go
EOF
if [ "$OTTEROP_DEPENDENCIES" = "local" ]; then
cat <<'EOF'

replace github.com/otterop/otterop/go => ../otterop/go
EOF
fi
cat <<'EOF'

go 1.18

require github.com/otterop/otterop/go v0.0.0-00010101000000-000000000000
EOF


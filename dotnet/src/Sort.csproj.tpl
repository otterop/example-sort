#!/bin/sh
cat <<'EOF'
<Project Sdk="Microsoft.NET.Sdk">

  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net7.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <StartupObject>Example.Sort.SortPure</StartupObject>
  </PropertyGroup>

  <ItemGroup>
EOF
if [ "$OTTEROP_DEPENDENCIES" = "local" ]; then
cat <<'EOF'
    <ProjectReference Include="../../otterop/dotnet/src/Io/Otterop.Io.csproj" />
    <ProjectReference Include="../../otterop/dotnet/src/Lang/Otterop.Lang.csproj" />
EOF
else
cat <<EOF
    <PackageReference Include="Otterop.Io" Version="$OTTEROP_VERSION" />
    <PackageReference Include="Otterop.Lang" Version="$OTTEROP_VERSION" />
EOF
fi
cat <<'EOF'
  </ItemGroup>
</Project>
EOF

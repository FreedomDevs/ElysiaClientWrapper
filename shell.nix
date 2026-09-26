{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
  nativeBuildInputs = with pkgs; [
    (pkgs.python3.withPackages (ps: with ps; [
      nbtlib
    ]))
    llvmPackages.clang-tools
    cmake
    ninja
    nlohmann_json

    qt6.qtbase
    qt6.qtwayland

  ];

  buildInputs = with pkgs; [
    fmt
    curl
  ];

  shellHook = ''
    export CPATH="${pkgs.glibc.dev}/include"
    export LIBRARY_PATH="${pkgs.glibc}/lib"
  '';
}

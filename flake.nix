{
  description = "Flake for qmk";

  inputs = {
    nixpks.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs{
          inherit system;
        };
      in
        with pkgs; {
            devShells.default = mkShell {
              buildInputs = [
                gnumake
                pkgs.pkgsCross.avr.buildPackages.gcc # for avr-gcc
                qmk
              ];
            };
          }
    );
}

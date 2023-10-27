#!/usr/bin/env bash

pnpm run build
git subtree push --prefix dist origin gh-pages

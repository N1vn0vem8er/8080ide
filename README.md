# 8080 IDE
Integrated development environment for Intel 8080 microprocessor.

## Table of contents

* [General info](#general-info)
* [Features](#features)
* [Technologies](#technologies)
* [Setup](#setup)

## General info

This is an integrated development environment for Linux that allows to create software for integrated simulator of 8080 microprocessor. It is meant for programmers who want to start learning assembly language.

## Features

* Simulator
* Assembler
* Debugger
* Code Editor with syntax highlighting
* Git integration
* Easy to access microprocessor instructions descriptions

## Technologies

This project was created with:

* Qt version: 6
* QTermWidget: 2.1.0

## Setup

Make sure you have Qt installed and configured. Clone this repo and run `install.sh` or :

```
$ mkdir build
$ cd build
$ qmake ../src/8080ide.pro
$ make
$ make install
```

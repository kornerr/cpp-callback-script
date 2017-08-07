# Overview

`cpp-callback-script` is a sample C++ application that is extended by a Lua script.

# Application structure

The sample application provides an abstraction to separate functionality
into several modules with the help of `Environment` and `EnvironmentClient`
classes.

Such a separation allows one to provide parts of the application either
as a C++ code, or a Lua one.

## Environment

The application has `Environment` that provides a member function
with the following signature:
`Strings call(const String &key, const Strings &values)`.

The function passes a list of string values (`std::vector`) to the specified
key and returns a result as another list of string values.

## EnvironmentClient

The application also has `EnvironmentClient` that serves as a callback
container for third parties wishing to interact indirectly through `Environment`.

`EnvironmentClient` has the following callbacks:
* `callbackRespondsToKey` returns a list keys this particular
  `EnvironmentClient` instance responds to
* `callbackCall` returns a list of keys as a result of running
  provided callback

The callbacks use `std::function` to remove the need for third parties
to inherit `EnvironmentClient` to specify custom behaviour.

## C++ side

`runCPP` function inside `main.cpp` registers two `EnvironmentClient`
instances that respond to different keys.

## Lua side

`runSol` function inside `main.cpp` registers `Environment`,
`EnvironmentClient` with Lua (using Sol2), and then runs `script.lua`.

`script.lua`, in its turn, creates an instance of `EnvironmentClient`
that responds to a new key.


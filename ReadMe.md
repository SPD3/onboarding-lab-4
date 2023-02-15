What is a registry?
A registry is the set of information stored about the packages within a project.

What is a package?
A package is the set of all source code files that are being used within a project.

What’s the difference between an interface library and a “normal” library or executable? Can you think of any uses for this besides System Verilog files? (Think about source code used for generic programming)
An interface library is a set of files that are not necessarily all going to be compiled immediately. Code and other files can be stored in interface libraries. Another use for an interface library is a library of only header files. If a library mostly consists only of header-files defining pure virtual classes, these files do not need need to be compiled immediately as they are only defining interfaces.
Source: https://cliutils.gitlab.io/modern-cmake/chapters/basics.html

What is a top module?
Top modules are the modules or source code files from which models should be made that will be exposed for simulations. Top modules exclude any modules that will not be tested on their own.

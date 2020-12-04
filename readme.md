# FaceFirst Engineering Tech Review

## Short Answer Question

> Collections/Containers are an integral part of software development. There are many varieties and all programming languages either have them built in, or they can be included from a third-party.<br>Choose a language in which you are most comfortable and proficient, choose two collections you have used while developing software, and, in a few sentences, talk about what the differences are between them and why you would use one over the other.


In Dlang I often use both arrays and ranges. Dlang offers lazy evaluation and ranges are a good way to implement laziness for various collections of data. Ranges have a few implementations but I will discuss input ranges.

Arrays are useful when multiple passes of data are required or if you need access to the length of the collection. Arrays in D are dynamic and offer easy appending using either the `~` or `~=` operator. The downside of using arrays is that it requires the entire collection to be available in memory and will require extra time to read the data into memory.

Ranges are useful when only one pass of the data is required. It allows computation to begin almost immediately as data will be read from the source only as it is needed by the program. Ranges are abstract and any object can be a range if it implements at least `front`, `popFront`, and `empty`.

## Building the project
In a developer command prompt

### Test
`cl source\test.c source\altseq.c source\excel_column.c`

`test.exe`

### altseq CLI
`cl source\altseq.c source\altseq_cli.c`

`altseq.exe`

### excel_column CLI
`cl source\excel_column.c source\excel_column_cli.c`

`excel_column.exe`

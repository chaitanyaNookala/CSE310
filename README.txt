Name(s): <your name>    Team alias: <your alias>

The program reads the number of slots K and a list of words from the input. 
It puts each and every word into a hash table with K slots, where each slot is a linked list, and the hash function will decide which slot each word goes into. 
The hash function reads the word one letter at a time and mixes the letters into a number, so that the same word always goes to the same slot. 
Words that land in the same slot will be chained together. 
At the end, the program prints the contents of the first five slots, the length of every slot, and the standard deviation of the slot lengths to four decimal places.
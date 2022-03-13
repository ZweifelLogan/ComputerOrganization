# Homework 5 - Cache Effects
In this homework we will explore our computer's cache.
Since we won't have much time to cover cache in-depth, this
homework is more of a lab than a typical homework assignment.
You will be graded more heavily on your approach and explanation
than the correctness of your answer. That being said, longer
explanations are not necessarily better.

## Tasks
1. Compile and run main.c using GCC. Save the output. (Note:
   the output is for your use only. Feel free to modify the output
   format however you see fit.)

   For this homework, I suggest you stick with GCC and avoid Clang.

## Questions
1. You should see several clusters of `elapsed_ns` that are averaged
   per block. The first cluster should stop at a block size of 64,
   with the next cluster (starting at 128) being either materially
   faster or slower. What is the significance of 64? Explain what
   is going on here.

2. Explain how these experiments work (at a high level). What is the
   purpose of the block size in our measurements? Why do we sample
   randomly instead of sequentially?

3. Determine the CPU of your computer - if you are running on the Linx
   cluster you may need to look up how to do this. On a Mac you can check
   in system properties. Look up the chip info on https://en.wikichip.org/.
   What are the values of the L2 and L3 (if your chip has an L3) cache for
   your chip? If you were to measure these, how would you modify the
   experiment?

4. One aspect of data-oriented programming is grouping your data by fields
   rather than by objects. That is, if you have an object representing a
   particle with speed and location fields, data-oriented programming
   suggests you have an array of all partical speeds and an array of all
   partical positions as opposed to the object-oriented approach of having
   an array of particle objects. In other words, we deconstruct the objects
   into arrays of their components. In this example, what would be the
   advantage of this approach if you wanted to compute the average particle
   speed or update all particle positions? For the sake of this example,
   suppose speed is represented by a single double and position is represented
   as a struct of three doubles.

	


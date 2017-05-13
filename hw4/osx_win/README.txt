My hw4 is built on top of the code from hw3. To build the code, 
type 
    make part2.
    ./part2 <color name>

Motion detection works well in simpler cases. 
I compared the difference between two frames and find boundaries of movements. 
Thresholds indicating the existence of motion are determined based on some experiments.

I drawed the trajectory line by plotting the center of mass of the detected object.
Considering the potential inaccuracy of the motion detector, I had to smooth it with
the center of mass of the previous object. The smoothing ratio is also determined based 
on some experiments. 

Note that the trajectory might not look like a "line". It looks more like a scatter plot.

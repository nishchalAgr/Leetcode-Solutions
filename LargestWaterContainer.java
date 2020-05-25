/*
---------------------------------------------------------------------------------------------
Written By: Nishchal Agrawal

Problem URL: https://leetcode.com/problems/container-with-most-water/

General Approach:
    Keep a pointer at the front and the back
    In each iteration:
        calulate area using front and back pointer and store area if it is max
        iterate front pointer if front value is smaller
        iterate back pointer if back value is smaller 
    stop iterating once the distance between front pointer and back pointer is 0

Leetcode Submission Metrics (May 25, 2020):
    Runtime: 2ms (95.25% percentile)
    Memory: 39.8MB (94.87% percentile)
---------------------------------------------------------------------------------------------
*/

class Main {

  public static int maxArea(int[] height) {
        
        int front = 0;                //have a front index that starts at index 0 and iterates forward
        int back = height.length - 1; //have a back index that starts at the end of the array and interates backwards
        int max = 0;
        
        while(back - front >= 1) {
            
            int current_height;
            
            int front_val = height[front];
            int back_val = height[back];

            //determine which height should be used in area calculation
            if (front_val < back_val) current_height =  front_val;
            else current_height = back_val;
            
            int area = current_height * (back - front); //calculate area
            
            if (area > max) { //check if current area is the max
                max = area; 
            }
            
            if (front_val < back_val) front++;    //iterate front index if front value is smaller
            else if (back_val < front_val) back--;//iterate back index if back value is smaller
            else {                                //if front and back value are equal, look at next front and back val
                
                int next_front = height[front + 1];
                int next_back = height[back - 1];
                
                if (next_front < next_back) back--;
                else if(next_front > next_back) front++;
                else front++;
            }
        }
       
        return max;
  }

  public static void main(String[] args) {
    int[] height = {2,3,4,5,18,17,6};
    System.out.println(maxArea(height));
  }
}
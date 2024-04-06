# Hospital Helpdesk Portal

| Date | 30th September 2022 |
| ---- | ------------------- |

| Function Name           | Description                                                                                                                                                                     |
|-------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **feedback_thingy()**   | Time Complexity: O(n), Space Complexity: O(n); used stack to store all feedbacks                                                                                                |
| **make_appointment()**  | Time Complexity: O(n), Space Complexity: O(n); space complexity is O(n) even though we used vector<vector<T>> because even though there are n vectors but each is of size 3 so total space is O(3*n) = O(n), traversing the same is O(n). We used unordered_map (to bridge between departments and their doctors), vectors, sets(to store unique departments) |
| **choose_main()**       | Time Complexity: O(n^2), Space Complexity: O(n) (n doctors and patient objects are being created) (we are appending doctor object and patient object to their respective linked list);  Space Complexity: O(n); when the application run for the first time, this function is called inside int main(), and all the data in the CSV file are being processed and populated in a linked list data structure. |
| **patient_show()**      | Time Complexity: O(n), Space Complexity: O(n); displays departments, doctors, their individual information used unordered_map, sets to achieve this                                 |
| **doctor_show()**       | Time Complexity: O(n), Space Complexity: O(n); displays departments, doctors, their individual information used unordered_map, sets to achieve this                                 |
| **patient_delete()**    | Time Complexity: O(n) (for login and traversing all doctors), Space Complexity: O(1) (in a row of a CSV file there are at most 10 elements — constant space to store a single row) |
| **doctor_delete()**     | Time Complexity: O(n) (for login and traversing all doctors), Space Complexity: O(1) (in a row of a CSV file there are at most 10 elements — constant space to store a single row) |
| **doctor_add()**        | Time Complexity: O(n), Space Complexity: O(1) (asks the details of the doctor and pushes back the doctor object to the linked list)                                                 |
| Overall Complexity      | Time Complexity: O(N^2), Space Complexity: O(N)                                                                                                                             

## Setup:

```bash
https://github.com/frostedCupcake/Learning-CPP-x-Hospital-Helpdesk-Portal.git
cd .\Learning-CPP-x-Hospital-Helpdesk-Portal\
g++ main.cpp
```

![image](/assets/readme-image.png)

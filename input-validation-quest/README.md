# Input validation tasks

> What tasks should input validation handle if i want positive one to three digit number with one decimal digit?

According to self hosted AI (mistral:latest)



> For a positive one to three digit number with one decimal digit, input validation should handle the following tasks:

> 1. Ensure that the input is not empty.
> 2. Verify that all characters in the input are digits or a decimal point (`'.'`).
> 3. Check if there's only one occurrence of the decimal point.
> 4. Make sure that the number of digits before the decimal is between 1 and 3.
> 5. Ensure that there's at least one digit after the decimal point.
> 6. Transform the input string to a double value, if possible, and check if it's positive and meets the specified constraints (e.g., with `std::to_string(number).length() <= 4` for the total number of digits).

function isPalindrome(string):
    // Step 1: Initialize a stack
    stack = createEmptyStack()
    
    // Step 2: Push all characters onto the stack
    for char in string:
        stack.push(char)
    
    // Step 3: Check for palindrome
    for char in string:
        if char != stack.pop():
            return False
    return True

// Example usage
string = "madam"
if isPalindrome(string):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

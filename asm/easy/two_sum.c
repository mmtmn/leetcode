__attribute__((naked)) int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    __asm__(
        ".intel_syntax noprefix;"
        "push rbp;"
        "mov rbp, rsp;"
        "sub rsp, 32;"                        // Allocate space for local variables
        
        "mov [rbp-4], edi;"                   // Store nums pointer
        "mov [rbp-8], esi;"                   // Store numsSize
        "mov [rbp-12], edx;"                  // Store target
        "mov [rbp-16], ecx;"                  // Store returnSize pointer

        "mov edi, 8;"                         // Allocate space for 2 integers (size is 8 bytes)
        "call malloc;"                        // Call malloc without underscore
        "mov [rbp-20], rax;"                  // Store the return array pointer
        "test rax, rax;"                      // Check if malloc failed
        "je allocate_fail;"                   // If rax is zero, malloc failed

        // Initialize variables
        "mov ebx, 0;"                         // i = 0

        "outer_loop_start:"
        "cmp ebx, [rbp-8];"                   // Compare i, numsSize
        "jge outer_loop_end;"                 // if i >= numsSize, end outer loop
        
        "mov ecx, ebx;"                       // j = i
        "add ecx, 1;"                         // j = i + 1
        "inner_loop_start:"
        "cmp ecx, [rbp-8];"                   // Compare j, numsSize
        "jge inner_loop_end;"                 // if j >= numsSize, end inner loop

        "mov eax, [rbp-4];"                   // Load nums pointer
        "mov edx, [eax + ebx * 4];"           // Load nums[i]
        "add edx, [eax + ecx * 4];"           // Load nums[j] and add to nums[i]
        "cmp edx, [rbp-12];"                  // Compare sum with target
        "jne increment_j;"                    // if not equal, go to increment_j
        
        // Found the pair
        "mov rdx, [rbp-20];"                  // Load address of return array
        "mov [rdx], ebx;"                     // Store i at return array[0]
        "mov [rdx + 4], ecx;"                 // Store j at return array[1]
        "mov eax, [rbp-20];"                  // Load address of return array into eax
        "mov [rbp-24], eax;"                  // Save it to a local variable
        
        "mov ecx, [rbp-16];"                  // Load returnSize pointer
        "mov dword ptr [ecx], 2;"             // Set *returnSize to 2
        "jmp cleanup;"                        // Clean up and return
        
        "increment_j:"
        "add ecx, 1;"                         // Increment j
        "jmp inner_loop_start;"               // Continue inner loop

        "inner_loop_end:"
        "add ebx, 1;"                         // Increment i
        "jmp outer_loop_start;"               // Continue outer loop

        "outer_loop_end:"
        "mov eax, 0;"                         // Set return value to NULL
        "mov [rbp-24], eax;"                  // Save it to local var

        "allocate_fail:"
        "mov eax, [rbp-24];"                  // Load return value
        "leave;"                              // Restore the previous stack frame
        "ret;"                                // Return to caller
        ".att_syntax;"
    );
}

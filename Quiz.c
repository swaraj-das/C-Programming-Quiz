#include <stdio.h>

void startQuiz();

int main() {
    int ch;
        printf("\n\n-:C PROGRAMMING QUIZ:-\n  ------------------");
    
    do {
        printf("\n\nTo start the quiz press: 1\nTo stop the quiz press: 0\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("\n\nThe quiz is starting...\n\n");
            startQuiz();
        } else if (ch == 0) {
            printf("Leaving the quiz.\n");
        } else {
            printf("Invalid Input!!\n");
        }
    } while (ch != 0);

    return 0;
}

void startQuiz() {
    printf("Each correct answer earns: 5 marks\n");
    printf("Each incorrect answer deducts: 1 mark\n");
    printf("Skipping a question gives: 0 marks\n");
    printf("Total Marks: 50\n");

    char *questions[10] = {
        "Who is known as the father of the C programming language?",
        "Which of the following is a valid C variable name?",
        "What is the output of the following code?\n#include <stdio.h>\nint main() {\n    int a = 5;\n    printf(\"%d\", a++);\n    return 0;\n}",
        "Which of the following is used to create a constant in C?",
        "What will be the output of the following code?\n#include <stdio.h>\nint main() {\n    int a = 10, b = 20;\n    printf(\"%d\", a + b);\n    return 0;\n}",
        "Which of the following functions is used to find the length of a string in C?",
        "What is the size of an int data type in C (assuming a 32-bit system)?",
        "Which of the following correctly declares an array of 10 integers in C?",
        "What is the correct syntax to declare a pointer to an integer in C?",
        "What will be the output of the following code?\n#include <stdio.h>\nvoid main() {\n    printf(\"Hello, World!\");\n}"
    };

    char *options[10][4] = {
        {"1. Bjarne Stroustrup", "2. Dennis Ritchie", "3. James Gosling", "4. Guido van Rossum"},
        {"1. 1variable", "2. variable_1", "3. variable-1", "4. @variable"},
        {"1. 4", "2. 5", "3. 6", "4. Compilation Error"},
        {"1. #define", "2. const", "3. constant", "4. Both 1 and 2"},
        {"1. 10", "2. 20", "3. 30", "4. 40"},
        {"1. strlen()", "2. strlength()", "3. length()", "4. str_len()"},
        {"1. 2 bytes", "2. 4 bytes", "3. 8 bytes", "4. 16 bytes"},
        {"1. int arr[10]", "2. int arr", "3. int arr[10][10]", "4. array int[10]"},
        {"1. int ptr;", "2. int *ptr;", "3. int &ptr;", "4. int ptr*;"},
        {"1. Hello, World!", "2. Compilation Error", "3. Runtime Error", "4. Hello, World"}
    };

    int answers[10] = {2, 2, 2, 4, 3, 1, 2, 1, 2, 1}; 
    int userAnswers[10];
    int score = 0;

    for (int i = 0; i < 10; i++) {
        printf("\nQ%d. %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", options[i][j]);
        }
        printf("Enter your answer (1-4) or 0 to skip: ");
        scanf("%d", &userAnswers[i]);

        if (userAnswers[i] == 0) {
            printf("Question Skipped\n");
            continue;
        } else if (userAnswers[i] == answers[i]) {
            score += 5;
            printf("Correct Answer\n");
        } else {
            score--;
            printf("Wrong Answer.. Correct answer is: %d\n", answers[i]);
        }
        printf("Current Score: %d\n", score);
    }

    printf("\nYou scored %d out of 50.\n", score);
}

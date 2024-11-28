#include <stdio.h>

void input();
void output(int c[]);
void setunion();
void intersection();
void difference();

int a[9] = {0}, b[9] = {0};  // Arrays to store the sets (0-8)

int main() {
    int ch, wish;
    do {
        printf("\n MENU \n");
        printf("1. Input\n2. Union\n3. Intersection\n4. Difference\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: 
                input();
                break;
            case 2: 
                setunion();
                break;
            case 3: 
                intersection();
                break;
            case 4: 
                difference();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        
        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &wish);
    } while (wish == 1);
    
    return 0;
}

void input() {
    int n, x, i;
    
    // Initialize arrays a and b to 0
    for (i = 0; i < 9; i++) {
        a[i] = b[i] = 0;
    }
    
    // Input for the first set
    printf("Enter size of the 1st set: ");
    scanf("%d", &n);
    printf("Enter elements of the 1st set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 0 && x <= 9) {
            a[x-1] = 1;
        } else {
            printf("Invalid element! Element should be between 1 and 9.\n");
            i--;  // To re-enter the element
        }
    }
    
    // Input for the second set
    printf("Enter size of the 2nd set: ");
    scanf("%d", &n);
    printf("Enter elements of the 2nd set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 0 && x <= 9) {
            b[x-1] = 1;
        } else {
            printf("Invalid element! Element should be between 1 and 9.\n");
            i--;  // To re-enter the element
        }
    }
    
    // Display the sets
    printf("\n1st set: ");
    output(a);
    printf("\n2nd set: ");
    output(b);
}

void output(int c[]) {
    int i;
    printf("{ ");
    for (i = 0; i < 9; i++) {
        if (c[i] != 0) {
            printf("%d ", i + 1);
        }
    }
    printf("}\n");
}

void setunion() {
    int i, c[9] = {0};
    for (i = 0; i < 9; i++) {
        if (a[i] == 1 || b[i] == 1) {
            c[i] = 1;
        }
    }
    printf("Union of the sets: ");
    output(c);
}

void intersection() {
    int i, c[9] = {0};
    for (i = 0; i < 9; i++) {
        if (a[i] == 1 && b[i] == 1) {
            c[i] = 1;
        }
    }
    printf("Intersection of the sets: ");
    output(c);
}

void difference() {
    int i, c[9] = {0};
    for (i = 0; i < 9; i++) {
        if (a[i] == 1 && b[i] == 0) {
            c[i] = 1;
        }
    }
    printf("Difference (A - B) of the sets: ");
    output(c);
}


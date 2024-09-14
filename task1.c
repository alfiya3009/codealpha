#include <stdio.h>
#include <string.h>

// Function to predict survival
int predict_survival(int age, char gender[], char ses[], char swimming_ability[]) {
    int survival_chance = 0;

    // Age factor
    if (age < 15 || age > 60) {
        survival_chance -= 1; 
    } else {
        survival_chance += 1;
    }

    // Gender factor
    if (strcmp(gender, "Female") == 0) {
        survival_chance += 1; 
    } else {
        survival_chance -= 1; 
    }

    // SES (Socio-Economic Status) factor
    if (strcmp(ses, "High") == 0) {
        survival_chance += 2; 
    } else if (strcmp(ses, "Medium") == 0) {
        survival_chance += 1; 
        survival_chance -= 1; 
    } 

    // Swimming Ability factor
    if (strcmp(swimming_ability, "Yes") == 0) {
        survival_chance += 2;
    } else {
        survival_chance -= 2; 
    }

    // Return 1 if likely to survive, 0 otherwise
    if (survival_chance > 0) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    int age;
    char gender[10], ses[10], swimming_ability[10];

    // Input data
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter gender (Male/Female): ");
    scanf("%s", gender);
    
    printf("Enter socio-economic status (High/Medium/Low): ");
    scanf("%s", ses);
    
    printf("Can the person swim? (Yes/No): ");
    scanf("%s", swimming_ability);

    // Predict survival
    int result = predict_survival(age, gender, ses, swimming_ability);

    // Output result
    if (result == 1) {
        printf("The person is likely to survive.\n");
    } else {
        printf("The person is unlikely to survive.\n");
    }

    return 0;
}

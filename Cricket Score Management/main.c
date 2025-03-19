#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OVERS 50
static int matchID = 1;

// Structure to store match details
struct Match {
    int matchID;
    char team1[50], team2[50];
    char tossWinner[50], tossDecision[10];
    int overs;
    int score1, wickets1, balls1;
    int score2, wickets2, balls2;
};

// Function to save match details in a file
void saveMatch(struct Match match) {
    FILE *file = fopen("match_history.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Match ID: %d\n", match.matchID);
    fprintf(file, "Match Between: %s vs %s\n", match.team1, match.team2);
    fprintf(file, "Toss Winner: %s, Decision: %s\n", match.tossWinner, match.tossDecision);
    fprintf(file, "Overs: %d\n", match.overs);
    fprintf(file, "Innings 1 Score: %d/%d in %d balls\n", match.score1, match.wickets1, match.balls1);
    fprintf(file, "Innings 2 Score: %d/%d in %d balls\n", match.score2, match.wickets2, match.balls2);
    if (match.score1 > match.score2) {
        fprintf(file, "Winner: %s\n\n", match.tossDecision[0] == 'B' ? match.tossWinner : (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1));
    } else if (match.score2 > match.score1) {
        fprintf(file, "Winner: %s\n\n", match.tossDecision[0] == 'B' ? (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1) : match.tossWinner);
    } else {
        fprintf(file, "Match Drawn\n\n");
    }
    fclose(file);
    matchID++;
}

// Function to display match details from file
void displayMatchHistory() {
    FILE *file = fopen("match_history.txt", "r");
    if (file == NULL) {
        printf("No match history found!\n");
        return;
    }
    char line[256];
    printf("\n---- Match History ----\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to play an innings
void playInnings(struct Match *match, int *score, int *wickets, int *balls, int target) {
    printf("\n--- Start Innings ---\n");
    *score = 0;
    *wickets = 0;
    *balls = 0;
    
    for (int over = 1; over <= match->overs; over++) {
        for (int ball = 1; ball <= 6; ball++) {
            int runs;
            printf("Enter runs for ball %d.%d (-1 for Wicket): ", over, ball);
            scanf("%d", &runs);
            
            if (runs == -1) {
                (*wickets)++;
            } else {
                (*score) += runs;
            }
            (*balls)++;
            
            printf("Score: %d/%d in %d.%d overs\n", *score, *wickets, over-1, ball);
            
            if (*wickets == 10) {
                printf("All Out!\n");
                return;
            }
            
            if (target > 0 && *score > target) {
                printf("Chasing team reached the target! Match over.\n");
                return;
            }
        }
    }
}

int main() {
    struct Match match;
    match.matchID = matchID;
    
    printf("Enter Team 1 Name: ");
    scanf("%s", match.team1);
    printf("Enter Team 2 Name: ");
    scanf("%s", match.team2);
    
    printf("Who won the toss? (%s/%s): ", match.team1, match.team2);
    scanf("%s", match.tossWinner);
    printf("Toss Decision (Bat/Bowl): ");
    scanf("%s", match.tossDecision);
    
    printf("Enter Number of Overs: ");
    scanf("%d", &match.overs);
    
    // First innings
    printf("\nFirst Innings: %s is batting\n", match.tossDecision[0] == 'B' ? match.tossWinner : (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1));
    playInnings(&match, &match.score1, &match.wickets1, &match.balls1, -1);
    
    // Second innings
    printf("\nSecond Innings: %s is batting\n", match.tossDecision[0] == 'B' ? (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1) : match.tossWinner);
    playInnings(&match, &match.score2, &match.wickets2, &match.balls2, match.score1);
    
    printf("\n--- Match Result ---\n");
    if (match.score1 > match.score2) {
        printf("Winner: %s\n", match.tossDecision[0] == 'B' ? match.tossWinner : (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1));
    } else if (match.score2 > match.score1) {
        printf("Winner: %s\n", match.tossDecision[0] == 'B' ? (strcmp(match.team1, match.tossWinner) == 0 ? match.team2 : match.team1) : match.tossWinner);
    } else {
        printf("Match Drawn\n");
    }
    
    saveMatch(match);
    
    printf("\nDo you want to view match history? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        displayMatchHistory();
    }
    
    return 0;
}

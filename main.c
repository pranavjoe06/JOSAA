#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variable declaration
int no_of_inst, no_of_branch_iit = 0, no_of_branch_nit = 0, seat_count = 0,
                no_of_iits = 0, no_of_nits = 0;
int maxstud = 200;
int max_pref_adv = 0, max_pref_main = 0;

// College structure
struct college {
  char name[20];
  char branch[30][20];
  int seats[20];
  int last_index[20];
};

// Student structure
struct Student {
  int rank;
  int regno;
  char name[30];
  char dob[11];
  int no_of_pref;
  char preferences[20][30];
  char allot[20];
  int allot_status;
};

// Creating IIT structure from user input
void create_college_iit(struct college IIT[]) {

  printf("\nEnter Number of IITs: ");
  scanf("%d", &no_of_iits);
  for (int i = 0; i < no_of_iits; i++) {
    char s[10];
    printf("\nEnter name of IIT: ");
    scanf("%s", s);
    strncat(IIT[i].name, s, sizeof(IIT[i].name) - 1);
  }
  char branches[20][20] = {};
  printf("\nEnter Number of Branches: ");
  scanf("%d", &no_of_branch_iit);
  for (int i = 0; i < no_of_branch_iit; i++) {
    char s[10];
    printf("\nEnter name of branch: ");
    scanf("%s", s);
    strncat(branches[i], s, sizeof(branches[i]) - 1);
  }
  for (int i = 0; i < no_of_iits; i++) {
    for (int j = 0; j < no_of_branch_iit; j++) {
      strncat(IIT[i].branch[j], branches[j], sizeof(IIT[i].branch[j]) - 1);
    }
  }
  printf("\nEnter number of seats: ");
  scanf("%d", &seat_count);
  for (int i = 0; i < no_of_iits; i++) {
    for (int j = 0; j < no_of_branch_iit; j++) {
      IIT[i].seats[j] = seat_count;
    }
  }
  max_pref_adv += (no_of_iits * no_of_branch_iit);
}

// Creating NIT structure from user input
void create_college_nit(struct college NIT[]) {

  printf("\nEnter Number of NITs: ");
  scanf("%d", &no_of_nits);
  for (int i = 0; i < no_of_nits; i++) {
    char s[10];
    printf("\nEnter name of NIT: ");
    scanf("%s", s);
    strncat(NIT[i].name, s, sizeof(NIT[i].name) - 1);
  }
  char branches[20][20] = {};
  printf("\nEnter Number of Branches: ");
  scanf("%d", &no_of_branch_nit);
  for (int i = 0; i < no_of_branch_nit; i++) {
    char s[10];
    printf("\nEnter name of branch: ");
    scanf("%s", s);
    strncat(branches[i], s, sizeof(branches[i]) - 1);
  }
  for (int i = 0; i < no_of_nits; i++) {
    for (int j = 0; j < no_of_branch_nit; j++) {
      strncat(NIT[i].branch[j], branches[j], sizeof(NIT[i].branch[j]) - 1);
    }
  }
  printf("\nEnter number of seats: ");
  scanf("%d", &seat_count);
  for (int i = 0; i < no_of_nits; i++) {
    for (int j = 0; j < no_of_branch_nit; j++) {
      NIT[i].seats[j] = seat_count;
    }
  }
  max_pref_main += (no_of_nits * no_of_branch_nit);
  max_pref_adv += max_pref_main;
}

// Generating static cases for colleges
void college_static(struct college IIT[], struct college NIT[]) {
  FILE *f1;
  f1 = fopen("colleges.txt", "r");
  if (f1 == NULL) {
    printf("No file exists");
    return;

  } else {

    fscanf(f1, "%d", &no_of_iits); // Number of iits
    for (int i = 0; i < no_of_iits; i++) {
      fscanf(f1, "%s", IIT[i].name);
    }
    fscanf(f1, "%d", &no_of_branch_iit); // Branches in iits
    char branches[20][20];
    for (int i = 0; i < no_of_branch_iit; i++) {
      fscanf(f1, "%s", branches[i]);
    }
    for (int i = 0; i < no_of_iits; i++) // Adding Branches to all iits
    {
      for (int j = 0; j < no_of_branch_iit; j++) {
        strncat(IIT[i].branch[j], branches[j], sizeof(IIT[i].branch[j]) - 1);
      }
    }
    fscanf(f1, "%d", &seat_count);
    for (int i = 0; i < no_of_iits; i++) {
      for (int j = 0; j < no_of_branch_iit; j++) {
        IIT[i].seats[j] = seat_count;
      }
    }
    fscanf(f1, "%d", &no_of_nits); // Number of iits
    for (int i = 0; i < no_of_nits; i++) {
      fscanf(f1, "%s", NIT[i].name);
    }
    fscanf(f1, "%d", &no_of_branch_nit); // Branches in iits
    char branches2[20][20] = {};
    for (int i = 0; i < no_of_branch_nit; i++) {
      fscanf(f1, "%s", branches2[i]);
    }
    for (int i = 0; i < no_of_nits; i++) // Adding Branches to all iits
    {
      for (int j = 0; j < no_of_branch_nit; j++) {
        strncat(NIT[i].branch[j], branches2[j], sizeof(NIT[i].branch[j]) - 1);
      }
    }
    fscanf(f1, "%d", &seat_count);
    for (int i = 0; i < no_of_nits; i++) {
      for (int j = 0; j < no_of_branch_nit; j++) {
        NIT[i].seats[j] = seat_count;
      }
    }

    max_pref_adv += (no_of_iits * no_of_branch_iit);
    max_pref_main += (no_of_nits * no_of_branch_nit);
    max_pref_adv += max_pref_main;
  }
}

// Reading JEE Mains ranklist
void read_ranklist_mains(struct Student stud_list[]) {
  FILE *fptr;
  fptr = fopen("ranklist_mains.txt", "r");
  int i = 0;
  char myString[100] = {};
  while (fgets(myString, 100, fptr)) {

    char sent[4][30] = {};
    for (int j = 0, k = 0; j < strlen(myString) - 1; j++) {
      if (myString[j] == ',') {
        k++;
      } else {
        char ch = (char)myString[j];
        strncat(sent[k], &ch, 1);
      }
    }
    stud_list[i].rank = atoi(sent[0]);
    stud_list[i].regno = atoi(sent[1]);
    strncat(stud_list[i].name, sent[2], sizeof(stud_list[i].name) - 1);
    strncat(stud_list[i].dob, sent[3], sizeof(stud_list[i].dob));
    i++;
  }
}

// Displaying candidate information from Mains ranklist
void display_ranklist_mains(struct Student stud_list_mains[200]) {
  for (int i = 0; i < 200; i++) {
    printf("\nRank:%d ", stud_list_mains[i].rank);
    printf("Regno:%d ", stud_list_mains[i].regno);
    printf("Name:%s ", stud_list_mains[i].name);
    printf("DOB:%s\n ", stud_list_mains[i].dob);
  }
}

// Reading JEE Advanced ranklist
void read_ranklist_adv(struct Student stud_list[]) {
  FILE *fptr;
  fptr = fopen("ranklist_adv.txt", "r");
  int i = 0;
  char myString[100] = {};
  while (fgets(myString, 100, fptr)) {

    char sent[4][30] = {};
    for (int j = 0, k = 0; j < strlen(myString) - 1; j++) {
      if (myString[j] == ',') {
        k++;
      } else {
        char ch = (char)myString[j];
        strncat(sent[k], &ch, 1);
      }
    }
    stud_list[i].rank = atoi(sent[0]);
    stud_list[i].regno = atoi(sent[1]);
    strncat(stud_list[i].name, sent[2], sizeof(stud_list[i].name) - 1);
    strncat(stud_list[i].dob, sent[3], sizeof(stud_list[i].dob));
    i++;
  }
}

// Displaying candidate information from Advanced ranklist
void display_ranklist_adv(struct Student stud_list[]) {
  for (int i = 0; i < 50; i++) {
    printf("\nRank:%d ", stud_list[i].rank);
    printf("Regno:%d ", stud_list[i].regno);
    printf("Name:%s ", stud_list[i].name);
    printf("DOB:%s\n ", stud_list[i].dob);
  }
}

// Generating random preferences for candidates
void random_preferences(struct Student stud_list[], struct college IIT[],
                        struct college NIT[]) {

  char arr[2][5] = {"IIT", "NIT"};
  int count;
  int max = 10000;
  for (int i = 0; i < 50; i++) {
    if (stud_list[i].preferences[0][0] == '\0') {
      int no_of_preferences = rand() % max_pref_adv + 1;
      stud_list[i].no_of_pref = no_of_preferences;
      // printf("\n%d ",no_of_preferences);
      for (int j = 0; j < no_of_preferences; j++) {
        count = 1;
        char pref[30] = {};
        int rando = rand() % 10;
        int IITorNIT;
        if (rando > 3)
          IITorNIT = 0;
        else
          IITorNIT = 1;
        int count = 1;
        // printf("%d ",co);
        // printf("%s ",arr[co]);
        if (IITorNIT == 0) {
          strncat(pref, arr[IITorNIT], sizeof(pref) - 1);
          int IITname = rand() % no_of_iits;
          strncat(pref, IIT[IITname].name, sizeof(pref) - 1);
          int BranchName = rand() % no_of_branch_iit;
          char c = '_';
          strncat(pref, &c, 1);
          strncat(pref, IIT[IITname].branch[BranchName], sizeof(pref) - 1);
          for (int q = 0; q < j; q++) {
            if (strcmp(pref, stud_list[i].preferences[q]) == 0) {
              j--;
              count = 0;
              break;
            }
          }
          if (count == 1)
            strncat(stud_list[i].preferences[j], pref,
                    sizeof(stud_list[i].preferences[j]) - 1);

        } else if (IITorNIT == 1) {
          strncat(pref, arr[IITorNIT], sizeof(pref) - 1);
          int NITname = rand() % no_of_nits;
          strncat(pref, NIT[NITname].name, sizeof(pref) - 1);
          int BranchName = rand() % no_of_branch_nit;
          char c = '_';
          strncat(pref, &c, 1);
          strncat(pref, NIT[NITname].branch[BranchName], sizeof(pref) - 1);
          for (int q = 0; q < j; q++) {
            if (strcmp(pref, stud_list[i].preferences[q]) == 0) {
              j--;
              count = 0;
              break;
            }
          }
          if (count == 1)
            strncat(stud_list[i].preferences[j], pref,
                    sizeof(stud_list[i].preferences[j]) - 1);
        }
      }
    }
  }
  for (int i = 50; i < 200; i++) {
    if (stud_list[i].preferences[0][0] == '\0') {
      int no_of_preferences = rand() % max_pref_main + 1;
      stud_list[i].no_of_pref = no_of_preferences;
      for (int j = 0; j < no_of_preferences; j++) {
        count = 1;
        char pref[20] = {};
        strncat(pref, arr[1], sizeof(pref) - 1);
        int NITname = rand() % no_of_nits;
        // printf("\n%d ",NITname);
        strncat(pref, NIT[NITname].name, sizeof(pref) - 1);
        int BranchName = rand() % no_of_branch_nit;
        // printf("%d",BranchName);
        char c = '_';
        strncat(pref, &c, 1);
        strncat(pref, NIT[NITname].branch[BranchName], sizeof(pref) - 1);
        for (int q = 0; q < j; q++) {
          if (strcmp(pref, stud_list[i].preferences[q]) == 0) {
            j--;
            count = 0;
            break;
          }
        }
        if (count == 1)
          strncat(stud_list[i].preferences[j], pref,
                  sizeof(stud_list[i].preferences[j]) - 1);
      }
    }
  }
}

// Choice filling of preferences by candidate
void change_preferences(struct Student stud_list[], int student_index,
                        struct college IIT[], struct college NIT[]) {
  printf("\nEnter the number of preferences to update: ");
  int num_preferences;
  scanf("%d", &num_preferences);
  stud_list[student_index].no_of_pref = num_preferences;

  printf("Enter Preferences\n");
  for (int i = 0; i < num_preferences; i++) {
    printf("Preference %d: ", i + 1);
    char preference[30] = {};
    scanf("%s", preference);

    int valid_preference = 0;
    if (student_index < 50) {
      if (strstr(preference, "IIT") != NULL) {
        for (int j = 0; j < no_of_iits; j++) {
          if (strstr(preference, IIT[j].name) != NULL) {
            for (int k = 0; k < no_of_branch_iit; k++) {
              if (strstr(preference, IIT[j].branch[k]) != NULL) {
                strncat(stud_list[student_index].preferences[i], preference,
                        sizeof(stud_list[student_index].preferences[i]) - 1);
                valid_preference = 1;
                break;
              }
            }
            if (valid_preference) {
              break;
            }
          }
        }
      } else if (strstr(preference, "NIT") != NULL) {
        for (int j = 0; j < no_of_nits; j++) {
          if (strstr(preference, NIT[j].name) != NULL) {
            for (int k = 0; k < no_of_branch_nit; k++) {
              if (strstr(preference, NIT[j].branch[k]) != NULL) {
                strncat(stud_list[student_index].preferences[i], preference,
                        sizeof(stud_list[student_index].preferences[i]) - 1);
                valid_preference = 1;
                break;
              }
            }
            if (valid_preference) {
              break;
            }
          }
        }
      }
    } else {
      for (int j = 0; j < no_of_nits; j++) {
        if (strstr(preference, NIT[j].name) != NULL) {
          for (int k = 0; k < no_of_branch_nit; k++) {
            if (strstr(preference, NIT[j].branch[k]) != NULL) {
              strncat(stud_list[student_index].preferences[i], preference,
                      sizeof(stud_list[student_index].preferences[i]) - 1);
              valid_preference = 1;
              break;
            }
          }
          if (valid_preference) {
            break;
          }
        }
      }
    }

    if (!valid_preference) {
      printf("Invalid preference: %s\n", preference);
      i--;
    }
  }

  printf("Preferences updated successfully.\n");
}

// To display preferences of students
void preferences(struct Student stud_list[]) {
  FILE *fp;
  fp = fopen("preferences.txt", "w");
  for (int i = 0; i < 200; i++) {
    fprintf(fp, "%d. ", i + 1);
    for (int j = 0; j < stud_list[i].no_of_pref; j++) {
      fprintf(fp, "%s, ", stud_list[i].preferences[j]);
    }
    if (i != 199)
      fprintf(fp, "\n");
  }
}

// Verifying candidate details
void verification(struct Student stud_list[], struct college IIT[],
                  struct college NIT[]) {
  printf("\nWelcome To JOSAA Counselling Login Portal!");
  for (;;) {
    char inp[5];
    printf("\nDo you wish to Login into portal(yes/no): ");
    scanf("%s", inp);
    if (strcmp(inp, "yes") == 0) {
      int user_id;
      char password[10];
      printf("\nENTER REGISTRATION NUMBER: ");
      scanf("%d", &user_id);
      printf("\nENTER PASSWORD: ");
      scanf("%s", password);
      int flag = -1;
      for (int i = 0; i < 200; i++) {
        if (user_id == stud_list[i].regno) {
          flag = i;
          printf("\n%d", flag);
        }
      }

      if (flag != -1) {
        if (strncmp(password, stud_list[flag].dob, 10) == 0) {
          printf("\nVerification Successful");
          change_preferences(stud_list, flag, IIT, NIT);
        } else
          printf("\nInvalid PASSWORD");
      } else
        printf("\nInvalid USER_ID");
    } else
      break;
  }
}

// To return student with higher JEE Adv rank
int adv_ranker(int regno1, int regno2, struct Student stud_list[]) {
  int index1, index2;
  for (int i = 0; i < 50; i++) {
    if (stud_list[i].regno == regno1) {
      index1 = i;
      break;
    }
  }
  for (int i = 0; i < 50; i++) {
    if (stud_list[i].regno == regno2) {
      index2 = i;
      break;
    }
  }
  if (index1 < index2)
    return 1;
  else
    return 0;
}

// To return JEE Adv Rank of Student
int advrank(int x, struct Student stud_list_adv[]) {
  for (int i = 0; i < 50; i++) {
    if (stud_list_adv[i].regno == x)
      return stud_list_adv[i].rank;
  }
  return 0;
}

// Allocating seats to candidates based on rank
void allotment(struct Student stud_list[], struct college IIT[],
               struct college NIT[], struct Student stud_list_adv[]) {
  int minadv[2][2] = {};
  for (;;) {
    int counter = 1;
    for (int i = 0; i < maxstud; i++) {

      if (stud_list[i].allot[0] == '\0') {
        int count = 1;
        for (int j = 0; j < stud_list[i].no_of_pref; j++) {

          char inst[20] = {};
          char instType[5] = {};
          char instName[10] = {};
          char branch[10] = {};
          char c = ',';
          char empty;
          sscanf(stud_list[i].preferences[j], "%[^_]_%s", inst, branch);
          for (int k = 0; k < 3; k++) {
            strncat(instType, &inst[k], 1);
          }
          for (int k = 3; inst[k] != '\0'; k++) {
            strncat(instName, &inst[k], 1);
          }
          if (strcmp(instType, "NIT") == 0) {
            int x, y;
            for (int m = 0; m < no_of_nits; m++) {
              if (strcmp(NIT[m].name, instName) == 0) {
                x = m;
                break;
              }
            }
            for (int m = 0; m < no_of_branch_nit; m++) {
              if (strcmp(NIT[x].branch[m], branch) == 0) {
                y = m;
                break;
              }
            }
            if (NIT[x].seats[y] > 1) {
              NIT[x].seats[y] -= 1;
              strncat(stud_list[i].allot, instType,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, NIT[x].name,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, NIT[x].branch[y],
                      sizeof(stud_list[i].allot) - 1);
              break;
            } else if (NIT[x].seats[y] == 1) {
              NIT[x].seats[y] -= 1;
              strncat(stud_list[i].allot, instType,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, NIT[x].name,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, NIT[x].branch[y],
                      sizeof(stud_list[i].allot) - 1);
              NIT[x].last_index[y] = i;
              break;
            } else if (NIT[x].seats[y] == 0 && maxstud == 200) {
              if (i < NIT[x].last_index[y]) {
                strncat(stud_list[i].allot, instType,
                        sizeof(stud_list[i].allot) - 1);
                strncat(stud_list[i].allot, &c, 1);
                strncat(stud_list[i].allot, NIT[x].name,
                        sizeof(stud_list[i].allot) - 1);
                strncat(stud_list[i].allot, &c, 1);
                strncat(stud_list[i].allot, NIT[x].branch[y],
                        sizeof(stud_list[i].allot) - 1);
                for (int l = 0;
                     stud_list[NIT[x].last_index[y]].allot[l] != '\0'; l++)
                  stud_list[NIT[x].last_index[y]].allot[l] = '\0';
                NIT[x].last_index[y] = i;
                counter = 0;
                break;
              }
            }

          } else if (strcmp(instType, "IIT") == 0) {
            int x, y;
            for (int k = 0; k < no_of_iits; k++) {
              if (strcmp(IIT[k].name, instName) == 0) {
                x = k;
                break;
              }
            }
            for (int k = 0; k < no_of_branch_iit; k++) {
              if (strcmp(IIT[x].branch[k], branch) == 0) {
                y = k;
                break;
              }
            }
            if (IIT[x].seats[y] > 1) {
              IIT[x].seats[y] -= 1;
              strncat(stud_list[i].allot, instType,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, IIT[x].name,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, IIT[x].branch[y],
                      sizeof(stud_list[i].allot) - 1);
              if (advrank(stud_list[i].regno, stud_list_adv) >
                  advrank(stud_list[IIT[x].last_index[y]].regno,
                          stud_list_adv)) {
                // minadv[x][y] = i;
                IIT[x].last_index[y] = i;
              }
              break;
            } else if (IIT[x].seats[y] == 1) {
              IIT[x].seats[y] -= 1;
              strncat(stud_list[i].allot, instType,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, IIT[x].name,
                      sizeof(stud_list[i].allot) - 1);
              strncat(stud_list[i].allot, &c, 1);
              strncat(stud_list[i].allot, IIT[x].branch[y],
                      sizeof(stud_list[i].allot) - 1);
              if (advrank(stud_list[i].regno, stud_list_adv) >
                  advrank(stud_list[IIT[x].last_index[y]].regno,
                          stud_list_adv)) {
                // minadv[x][y] = i;
                IIT[x].last_index[y] = i;
              }
              break;
            } else if (IIT[x].seats[y] == 0 && maxstud == 200) {
              int high = adv_ranker(stud_list[i].regno,
                                    stud_list[IIT[x].last_index[y]].regno,
                                    stud_list_adv);
              if (high == 1) {
                strncat(stud_list[i].allot, instType,
                        sizeof(stud_list[i].allot) - 1);
                strncat(stud_list[i].allot, &c, 1);
                strncat(stud_list[i].allot, IIT[x].name,
                        sizeof(stud_list[i].allot) - 1);
                strncat(stud_list[i].allot, &c, 1);
                strncat(stud_list[i].allot, IIT[x].branch[y],
                        sizeof(stud_list[i].allot) - 1);
                for (int l = 0;
                     stud_list[IIT[x].last_index[y]].allot[l] != '\0'; l++)
                  stud_list[IIT[x].last_index[y]].allot[l] = '\0';
                IIT[x].last_index[y] = i;

                counter = 0;
                break;
              }
            }
          }
        }
      }
    }
    if (counter == 1)
      break;
  }
}

// To display allotment of Student
void display_allot(char *filename, struct Student stud_list[]) {
  FILE *fp;
  fp = fopen(filename, "w");
  for (int i = 0; i < maxstud; i++) {
    // printf("\n%d. REG NO: %d, NAME: %s, ALLOTMENT: %s", i +
    // 1,stud_list[i].regno, stud_list[i].name, stud_list[i].allot);
    fprintf(fp, "%d. REG NO: %d, NAME: %s, ALLOTMENT: %s", i + 1,
            stud_list[i].regno, stud_list[i].name, stud_list[i].allot);
    if (i != maxstud - 1)
      fprintf(fp, "\n");
  }
  printf("\n");
}

void seatdecline(int index, struct Student stud_list[], struct college NIT[],
                 struct college IIT[]) {
  char a[5];
  char clg[3][20] = {};
  char inst[5];
  char instName[20];
  char branch[10];
  stud_list[index].allot_status = 0;
  for (int k = 0, j = 0; stud_list[index].allot[k] != '\0'; k++) {
    if (stud_list[index].allot[k] == ',')
      j++;
    else {
      strncat(clg[j], &stud_list[index].allot[k], 1);
    }
  }
  strcpy(inst, clg[0]);
  strcpy(instName, clg[1]);
  strcpy(branch, clg[2]);
  for (int k = 0; stud_list[index].allot[k] != '\0'; k++) {
    stud_list[index].allot[k] = '\0';
  }
  if (strcmp(inst, "IIT") == 0) {
    int x, y;
    for (int k = 0; k < no_of_iits; k++) {
      if (strcmp(IIT[k].name, instName) == 0) {
        x = k;
        break;
      }
    }
    for (int k = 0; k < no_of_branch_iit; k++) {
      if (strcmp(IIT[x].branch[k], branch) == 0) {
        y = k;
        break;
      }
    }
    IIT[x].seats[y] += 1;
  }
  if (strcmp(inst, "NIT") == 0) {
    int x, y;
    for (int k = 0; k < no_of_nits; k++) {
      if (strcmp(NIT[k].name, instName) == 0) {
        x = k;
        break;
      }
    }
    for (int k = 0; k < no_of_branch_nit; k++) {
      if (strcmp(NIT[x].branch[k], branch) == 0) {
        y = k;
        break;
      }
    }
    NIT[x].seats[y] += 1;
  }
}

// To confirm allotted seat
void seat_confirmation(struct Student stud_list[], struct college NIT[],
                      struct college IIT[]) {
  FILE *fptr;
  fptr = fopen("seat_confirm.txt", "r");

  for (int i = 0; i < 200; i++) {
    char a[5];
    char clg[3][20] = {};
    char inst[5];
    char instName[20];
    char branch[10];
    if (stud_list[i].allot[0] == '\0') {
      stud_list[i].allot_status = 2;
      fscanf(fptr, "%s", a);
    } else {
      fscanf(fptr, "%s", a);
      if (strcmp(a, "no") == 0) {
        stud_list[i].allot_status = 0;
        for (int k = 0, j = 0; stud_list[i].allot[k] != '\0'; k++) {
          if (stud_list[i].allot[k] == ',')
            j++;
          else {
            strncat(clg[j], &stud_list[i].allot[k], 1);
          }
        }
        strcpy(inst, clg[0]);
        strcpy(instName, clg[1]);
        strcpy(branch, clg[2]);

        for (int k = 0; stud_list[i].allot[k] != '\0'; k++) {
          stud_list[i].allot[k] = '\0';
        }
        if (strcmp(inst, "IIT") == 0) {
          int x, y;
          for (int k = 0; k < no_of_iits; k++) {
            if (strcmp(IIT[k].name, instName) == 0) {
              x = k;
              break;
            }
          }
          for (int k = 0; k < no_of_branch_iit; k++) {
            if (strcmp(IIT[x].branch[k], branch) == 0) {
              y = k;
              break;
            }
          }
          IIT[x].seats[y] += 1;
        }
        if (strcmp(inst, "NIT") == 0) {
          int x, y;
          for (int k = 0; k < no_of_nits; k++) {
            if (strcmp(NIT[k].name, instName) == 0) {
              x = k;
              break;
            }
          }
          for (int k = 0; k < no_of_branch_nit; k++) {
            if (strcmp(NIT[x].branch[k], branch) == 0) {
              y = k;
              break;
            }
          }
          NIT[x].seats[y] += 1;
        }

      } else {
        stud_list[i].allot_status = 1;
      }
    }
  }
}

// To check for availability of seats
int remaining_seat(struct college NIT[], struct college IIT[]) {
  int count = 0;
  for (int i = 0; i < no_of_iits; i++) {
    for (int j = 0; j < no_of_branch_iit; j++) {
      if (IIT[i].seats[j] > 0)
        return 1;
    }
  }
  for (int i = 0; i < no_of_nits; i++) {
    for (int j = 0; j < no_of_branch_nit; j++) {

      if (NIT[i].seats[j] > 0)
        return 1;
    }
  }
  return 0;
}

// To display seats left unfilled
void seat_available(struct college IIT[], struct college NIT[]) {
  printf("\n\tINSTITUTE\t\tCOURSE\t\tSEATS AVAILABLE\n");
  int k = 0;
  for (int i = 0; i < no_of_iits; i++) {
    for (int j = 0; j < no_of_branch_iit; j++) {
      printf("\n%-3d %3s%-10s%5s%20d", ++k, "IIT", IIT[i].name,
             IIT[i].branch[j], IIT[i].seats[j]);
    }
  }
  for (int i = 0; i < no_of_nits; i++) {
    for (int j = 0; j < no_of_branch_nit; j++) {
      printf("\n%-3d %3s%-10s%5s%20d", ++k, "NIT", NIT[i].name,
             NIT[i].branch[j], NIT[i].seats[j]);
    }
  }
}

// MAIN METHOD
int main() {

  struct Student stud_list_mains[200] = {};
  struct Student stud_list_adv[50] = {};
  struct college IIT[20] = {};
  struct college NIT[20] = {};
  char login[20];
  int user_id;
  int index;
  char password[10];
  int round = 0;
  // create_college_iit(IIT); //To take input from user
  // create_college_nit(NIT);  //To take input from user
  college_static(IIT, NIT); // To generate random colleges from file

  read_ranklist_mains(stud_list_mains);

  read_ranklist_adv(stud_list_adv);

  printf("\n\t\t\t\t\t\033[1;31mWelcome To JoSAA Counselling Login "
         "Portal!\033[0m\n\n");
  printf("\n*******************************************************************"
         "*********************");

  printf(
      "\n\t\t\033[1;94m1.ABOUT\t\t\t\t\t\t\t\t\t\t2.CANDIDATE LOGIN\033[0m\n");

  printf("\n\t%-20s\t\t\t\t\t\t\t\t%-10s", "-> View Mains Ranklist",
         "-> Login");
  printf("\n\t%-20s\t\t\t\t\t\t\t\t\t\t", "-> View Advanced Ranklist");
  printf("\n\t%-20s\t\t\t\t\t\t\t\t\t\t", "-> View Available Courses");

  int count = 0;
  char ch[5];
  printf("\n\n\033[1;92mWould you like to browse the ABOUT section? (yes/no): "
         "\033[0m");

  scanf("%s", ch);

  if (strcmp(ch, "yes") == 0) {
    int choice;
    do {
      printf("\n\nABOUT MENU\n1 - View Mains Ranklist\n2 - View Advanced "
             "Ranklist\n3 "
             "- View Offerred Courses\n4 - Back to Homepage\n");

      printf("Enter choice : ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
        display_ranklist_mains(stud_list_mains);
        break;

      case 2:
        display_ranklist_adv(stud_list_adv);
        break;

      case 3:
        seat_available(IIT, NIT);
        break;

      case 4:
        printf("\nRedirecting to HOMEPAGE...\n\n");
        break;

      default:
        printf("\nInvalid option.Try again...\n");
      }
    } while (choice != 4);
  }

here:
  printf("\n\033[1;92mDo you wish to LOGIN into portal? (yes/no): \033[0m");
  scanf("%s", login);

  if (strcmp(login, "yes") == 0) {
    count = 1;
    printf("\nENTER REGISTRATION NUMBER: ");
    scanf("%d", &user_id);
    printf("\nENTER PASSWORD: ");
    scanf("%s", password);
    int flag = -1;
    for (int i = 0; i < 200; i++) {
      if (user_id == stud_list_mains[i].regno) {
        flag = i;
        index = i;
      }
    }

    if (flag != -1) {

      if (strncmp(password, stud_list_mains[flag].dob, 10) == 0) {

        printf("\n\t\t\t\t\033[1;96mVerification Successful!\033[0m\n");
        printf("\n\t\t\t\t\tCANDIDATE DETAILS ");
        printf("\nRegister Number: %d", stud_list_mains[flag].regno);
        printf("\nName: %s", stud_list_mains[flag].name);
        printf("\nDOB: %s", stud_list_mains[flag].dob);
        printf("\nJEE Mains Rank: %d", stud_list_mains[flag].rank);
        int rank = advrank(stud_list_mains[flag].regno, stud_list_adv);
        printf("\nJEE Advanced Rank: %d", rank);

        if (flag < 50) {
          printf("\nEligibility Status: Eligible for Advanced\n");
        } else {
          printf("\nEligibility Status: Not eligible for Advanced\n");
        }

        change_preferences(stud_list_mains, flag, IIT, NIT);

      } else {
        printf("\nInvalid PASSWORD");
        goto here;
      }
    } else {
      printf("\nInvalid REGISTER NUMBER\n");
      goto here;
    }
  }
  printf("\nhi");
  random_preferences(stud_list_mains, IIT, NIT);
  printf("\nhii");
  preferences(stud_list_mains);
  printf("\nhiii");
  allotment(stud_list_mains, IIT, NIT, stud_list_adv);
  printf("\nhiiii");
  ++round;
  printf("\n\t\t\t\t\t\t\t\033[1;95mJoSAA COUNSELLING BEGINS!\033[0m\n");

  printf("\n*******************************************************************"
         "*********************");
  printf("\n\t\t\t\t\t\t\t\033[1;96mCounselling Round: %d\033[0m\n", round);

  printf("\n*******************************************************************"
         "*********************");
  if (count == 1) {
    printf("\n\n\t\t\t\t\tCANDIDATE ALLOTMENT ");
    printf("\nRegister Number: %d", stud_list_mains[index].regno);
    printf("\nName: %s", stud_list_mains[index].name);
    printf("\nDate of Birth: %s", stud_list_mains[index].dob);
    printf("\nAllotment: %s\n", stud_list_mains[index].allot);
    printf("\nAccept seat allotted(yes/no): ");
    scanf("%s", ch);
    if (strcmp(ch, "no") == 0) {
      seatdecline(index, stud_list_mains, NIT, IIT);
    }
  }

  display_allot("round1_allot.txt", stud_list_mains);
  seat_confirmation(stud_list_mains, NIT, IIT);

  printf("\n\033[1;92mDo you wish to see number of seats available after Round "
         "1(yes/no): \033[0m");

  scanf("%s", ch);

  if (strcmp(ch, "yes") == 0)
    seat_available(IIT, NIT);
  if (remaining_seat(NIT, IIT) == 1) {
    printf("\n*****************************************************************"
           "***********************");
    printf("\n\t\t\t\t\t\t\t\033[1;96mCounselling Round: %d\033[0m\n", ++round);

    printf("\n*****************************************************************"
           "***********************");
    struct Student stud_list2[200] = {};
    int stud_count = 0;
    for (int i = 0, j = 0; i < 200; i++) {
      if (stud_list_mains[i].allot_status == 2) {
        stud_list2[j].regno = stud_list_mains[i].regno;
        stud_list2[j].regno = stud_list_mains[i].regno;
        strcpy(stud_list2[j].name, stud_list_mains[i].name);
        strcpy(stud_list2[j].name, stud_list_mains[i].name);
        stud_list2[j].no_of_pref = stud_list_mains[i].no_of_pref;
        for (int k = 0; k < stud_list_mains[i].no_of_pref; k++) {
          strncat(stud_list2[j].preferences[k],
                  stud_list_mains[i].preferences[k],
                  sizeof(stud_list2[j].preferences[k]) - 1);
        }
        j++;
        stud_count++;
      }
    }
    maxstud = stud_count;

    for (int i = 0; i < no_of_iits; i++) {
      for (int j = 0; j < no_of_branch_iit; j++) {
        IIT[i].last_index[j] = 200;
      }
    }
    for (int i = 0; i < no_of_nits; i++) {
      for (int j = 0; j < no_of_branch_nit; j++) {
        NIT[i].last_index[j] = 200;
      }
    }
    allotment(stud_list2, IIT, NIT, stud_list_adv);
    ++round;
    display_allot("round2_allot.txt", stud_list2);
  }

  return 0;
}

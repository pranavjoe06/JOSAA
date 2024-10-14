# SOFTWARE SYSTEM ENGINEERING FOR JOINT SEAT ALLOCATION
The code below uses the Gale-Shapley Algorithm to allocate seats from two sets of institutes (IITs and NITs). The institutes have a number of branches and finite number of seats.
Candidates can login into the portal and update their preferences. After that a random set of preferences are generated for candidates. The seats are then allocated using the Gale-Shapley Algorithm. The candidate can then accept or deny seat. The unallotted students are then complied into the second round of counselling.

## Files
The folder contains 7 text files namely - colleges.txt, preferences.txt, ranklist_adv.txt, ranklist_mains.txt, round1_allot.txt, round2_allot.txt, seat_confirm.txt.
main.c is the single executable c file present. 
Details of the candidates are present in the ranklist_mains.txt and ranklist_adv.txt.
[preferences.txt](https://github.com/pranavjoe06/JOSAA/files/12086139/preferences.txt),
[colleges.txt](https://github.com/pranavjoe06/JOSAA/files/12086137/colleges.txt),
[ranklist_adv.txt](https://github.com/pranavjoe06/JOSAA/files/12086153/ranklist_adv.txt),
[ranklist_mains.txt](https://github.com/pranavjoe06/JOSAA/files/12086248/ranklist_mains.txt),
[round1_allot.txt](https://github.com/pranavjoe06/JOSAA/files/12086445/round1_allot.txt),
[seat_confirm.txt](https://github.com/pranavjoe06/JOSAA/files/12086530/seat_confirm.txt),
[round2_allot.txt](https://github.com/pranavjoe06/JOSAA/files/12086525/round2_allot.txt)


## Execution
The main.c file is exceuted and from the ranklist_main.txt file the Register number and Date of Birth of candidate can be used to login and update preferences. Preferences to be given in the format "IITname_branch".





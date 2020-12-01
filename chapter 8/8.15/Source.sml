//sml app a)
00	+1008	; read keyboard input to location 07
01	+2008	; load 07 to accumulator
02	+4106	; branch to 05 if accumulator is negative
03	+3009	; add 08 to accumulator
04	+2109	; store accumulator to 08
05	+4000	; read the next number
06	+1109	; write 09 to screen
07	+4300	; halt
08	+0000	; data word initialized to 0
09	+0000	; data word initialized to 0
//end

//sml app b)
00	+1017	; read keybord input to localtion user input data word
01	+2018	; load count to accumulator
02	+3019	; acuumulator++
03	+2118	; store count to *count
04	+3120	; accumulator - 7
05	+4211	; goto 11 if accumulator == 0 <- got seven numbers
06	+2017	; load userinput to accumulator
07	+3021	; accumulator += sum
08	+2121	; store accumulator to sum
09	+3121	; accumulator set to 0
10	+4200	; goto 00
11	+2021	; load sum
12  +3017	; sum += userInput
13	+3220	; sum /= 7
14	+2122	; store sum / 7 to result
15	+1122	; write result to screen
16	+4300	; halt
17	+0000	; data word to store user input
18	+0000	; data word to store count
19	+0001	; data word to represent 1
20	+0007	; data word to represent 7
21	+0000	; data word to store sum
22	+0000	; data word to store result
//end

//sml app c)
00	+1024	; read to counterLimit
01	+2024	; load counterLimit to accumulator
02	+4120	; halt if counterLimit is negative
03	+4220	; halt if counterLimit is zero
04	+1025	; read to number	/*readNextNumber()*/ ~ 09
05	+2026	; load counter(which was initialized to zero)
06	+3027	; counter++
07	+2126	; store the counter
08	+3127	; accumulator/counter - 1 = accumulator
09	+4221	; goto initialize max
10	+2024	; load the counterLimit
11	+3126	; substract counter from accumulator/counterLimit
12	+4219	; have read the needed number of numbers
13	+2025	; load number
14	+3128	; number - max -> accumulator
15	+4104	; branch to *readNextNumber() if max > number
16	+2025	; load number	/*replaceMax()*/ ~ 19
17	+2128	; replace max with number
18	+4004	; read the next number
19	+1128	; *showMax()	/*showMax()*/ ~ 21
20	+4300	; halt
21	+2025	; load number	/*initMax()*/ ~ 25
22	+2128	; init max = number;
23	+4004	; read the next number
24	+0000	; counterLimit	/*data*/ ~ 30
25	+0000	; number
26	+0000	; counter
27	+0001	; 1
28	+0000	; max
//end

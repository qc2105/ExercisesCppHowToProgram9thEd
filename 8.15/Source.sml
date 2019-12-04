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
00	+1026	; read to counterLimit
01	+2026	; load counterLimit to accumulator
02	+4121	; halt if counterLimit is negative
03	+4221	; halt if counterLimit is zero
04	+1027	; read to number	/*readNextNumber()*/ ~ 09
05	+2028	; load counter(which was initialized to zero)
06	+3029	; counter++
07	+2128	; store the counter
08	+3129	; accumulator/counter - 1 = accumulator
09	+4222	; goto initialize max
10	+2026	; load the counterLimit
11	+3128	; substract counter from accumulator/counterLimit
12	+4220	; have read the needed number of numbers
13	+2027	; load number
14	+3130	; number - max -> accumulator
15	+4104	; branch to *readNextNumber() if max > number
16	+2027	; load number	/*replaceMax()*/ ~ 19
17	+2130	; replace max with number
18	+3130	; accumulator -> 0
19	+4204	; branch to *readNextNumber() if accumulator = 0;
20	+1130	; *showMax()	/*showMax()*/ ~ 21
21	+4300	; halt
22	+2027	; load number	/*initMax()*/ ~ 25
23	+2130	; init max = number;
24	+3130	; accumulator = 0
25	+4204	; read next number
26	+0000	; counterLimit	/*data*/ ~ 30
27	+0000	; number
28	+0000	; counter
29	+0001	; 1
30	+0000	; max
//end

//sml app a)
00	+1007	; read keyboard input to location 07
01	+2007	; load 07 to accumulator
02	+4105	; branch to 05 if accumulator is negative
03	+3008	; add 08 to accumulator
04	+2108	; store accumulator to 08
05	+1108	; write 08 to screen
06	+4300	; halt
07	+0000	; data word initialized to 0
08	+0000	; data word initialized to 0
//end

//sml app b)
00	+1016	; read keybord input to localtion user input data word
01	+2017	; load count to accumulator
02	+3018	; acuumulator++
03	+2117	; store count to *count
04	+3119	; accumulator -7
05	+4211	; goto 11 if accumulator == 0 <- got seven numbers
06	+2016	; load userinput to accumulator
07	+3020	; accumulator += sum
08	+2120	; store accumulator to sum
09	+3120	; accumulator set to 0
10	+4200	; goto 00
11	+2020	; load sum
12	+3219	; sum /= 7
13	+2121	; store sum / 7 to result
14	+1121	; write result to screen
15	+4300	; halt
16	+0000	; data word to store user input
17	+0000	; data word to store count
18	+0001	; data word to represent 1
19	+0007	; data word to represent 7
20	+0000	; data word to store sum
21	+0000	; data word to store result
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

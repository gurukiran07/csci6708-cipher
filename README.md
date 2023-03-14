# CSCI 6708 - Assignment 4

## File structure:

```
csci6708-cipher
├── Makefile
├── README.md
├── headers
│   ├── playfair.h
│   └── transposition.h
├── plain-text.txt
└── src
    ├── main.cpp
    ├── playfair.cpp
    └── transposition.cpp
```

`.cpp` files are inside `src/` folder and all the header are inside `headers/` folder. The input text `plain-text.txt` is in the top-most directory `csci6708-cipher/`.

## Setup the code

Download the file and maintain the above file structure. The files are uploaded to brightspace, github and git.cs.dal.ca.

- [`Github repo`](https://github.com/gurukiran07/csci6708-cipher)
- [`git.cs.dal.ca repo`](https://git.cs.dal.ca/jagata/csci6708-cipher)

```
$ git clone git@github.com:gurukiran07/csci6708-cipher.git
```

## Running the code

After cloning or downloading from brightspace change into `csci6708-cipher/` directory. Now, run `make` to compile and run the code.

```
$ cd csci6708-cipher/
csci6708-cipher/ $ make
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wsign-compare -Wall -Werror -I headers/ -c src/playfair.cpp -o playfair.o
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wsign-compare -Wall -Werror -I headers/ -c src/transposition.cpp -o transposition.o
g++ -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wsign-compare -Wall -Werror -I headers/ playfair.o transposition.o src/main.cpp -o main
./main 
=====================PLAYFAIR CIPHER=====================

MATRIX:
R A Y Q U 
Z B C D E 
F G H I K 
L M N O P 
S T V W X 

PLAIN TEXT: POKEMON TOWER DEFENSE
YOUR MISSION IN THIS FUN STRATEGY TOWER DEFENSE GAME IS TO HELP PROFESSOR OAK TO STOP ATTACKS OF WILD RATTATA. SET OUT ON YOUR OWN POKEMON JOURNEY, TO CATCH AND TRAIN ALL POKEMON AND TRY TO SOLVE THE MYSTERY BEHIND THESE ATTACKS. YOU MUST PLACE POKEMON CHARACTERS STRATEGICALLY ON THE BATTLEFIELD SO THAT THEY STOP ALL WAVES OF ENEMY ATTACKER
DURING THE BATTLE YOU WILL LEVEL UP AND EVOLVE YOUR POKEMON. YOU CAN ALSO CAPTURE OTHER
 
POKEMON DURING THE BATTLE AND ADD THEM TO YOUR TEAM. USE YOUR MOUSE TO PLAY THE GAME. GOOD LUCK

SECRET KEY: RAYQUAZA

ENCRYPTED TEXT: LPPKNPMVWQZUEZKZLVCUPQALFWWFPOHOVGFWKRLVSABABKAVWQZUEZKZLVBKBTDKTVNIZPOULULIZXWLQLUGWMTVPLBAABEHWLISFOZQBAABABXZWMAXPOQNRAWQOLPIBPPOOWRAPCAVNDBAHNYMBWAYHORMMLPIBPPOYMBWAQWMWLNSBXKCNATVZUACCKHOBWKCXZBAABEHVRPQPATVLMYBKXPIBPPOHNYAYBXBZRTVAYXBHKBYORNRPOVGZCBASMZKKDOZWLVGBAVGCUTVPLRMOSYTZXLICPBPQYWAABEHZUEQQFMHVGZCBASMCUPQQOORORPZXCPRMUOCCXPMXCQNRALPPKNPVCPQBYMYSRNDUMXAUZMWKCULPIBPPOEQQFMHVGZCBASMBUOCQBBWKCTANQPQASBUPAXZQNRANPRXBXPLMRAVKCMBPBIMWIPREH

DECRYPTED TEXT: POKEMONTOWERDEFENSEYOURMISSIONINTHISFUNSTRATEGYTOWERDEFENSEGAMEISTOHELPQPROFESSOROAKTOSTOPATTACKSOFWILDRATTATASETOUTONYOUROWNPOKEMONIOURNEYTOCATCHANDTRAINALLPOKEMONANDTRYTOSOLVETHEMYSTERYBEHINDTHESEATTACKSYOUMUSTPLACEPOKEMONCHARACTERSSTRATEGICALQLYONTHEBATTLEFIELDSOTHATTHEYSTOPALLWAVESOFENEMYATQTACKERDURINGTHEBATTLEYOUWILQLQLEVELUPANDEVOLVEYOURPOKEMONYOUCANALSOCAPTUREOTHERPOKEMONDURINGTHEBATTLEANDADDTHEMTOYOURTEAMUSEYOURMOUSETOPLAYTHEGAMEGOODLUCK

============================================================


=====================MATRIX TRANSPOSITION CIPHER============

PLAIN TEXT: POKEMON TOWER DEFENSE
YOUR MISSION IN THIS FUN STRATEGY TOWER DEFENSE GAME IS TO HELP PROFESSOR OAK TO STOP ATTACKS OF WILD RATTATA. SET OUT ON YOUR OWN POKEMON JOURNEY, TO CATCH AND TRAIN ALL POKEMON AND TRY TO SOLVE THE MYSTERY BEHIND THESE ATTACKS. YOU MUST PLACE POKEMON CHARACTERS STRATEGICALLY ON THE BATTLEFIELD SO THAT THEY STOP ALL WAVES OF ENEMY ATTACKER
DURING THE BATTLE YOU WILL LEVEL UP AND EVOLVE YOUR POKEMON. YOU CAN ALSO CAPTURE OTHER
 
POKEMON DURING THE BATTLE AND ADD THEM TO YOUR TEAM. USE YOUR MOUSE TO PLAY THE GAME. GOOD LUCK

SECRET KEY: {3, 4, 1, 2} 

ENCRYPTED TEXT: KNWDNY%S%T%%AYWDNG%TEPERK%PTS%DTAEUNUWOOOETA%%ILOONROLTMEBNH%A.USL%E%RESTCY%%TI%T%YOLA%EYTEUGET%%LVUNVEUOOYCA%T%E%E%ITBLNDHTOT.EUO%P%%EOL%E%EESOMIIHFST%EESAIOLRS%%S%A%W%T.TT%RNKNUYOTATNLKNDY%VHYREDEAC%%TAPMCARTEA%TBLESHT%PLVON%ARR%%TYW%EPDO%RKNOALCUORPMDNHAEDDEOUE%%RUTLTG.OU%PMTRFEUIONIUTETRFEMS%POSOTTACOIRA%%%Y%%E%R,%CNR%%E%%%SEESYH%STKYM%COOHCSRGLOHAELOAHS%%EFEAC%ITBLOILL%%LY%E.UNSART%OOUGET%%%M%RAUY%SOAHA%DCOOO%E%RSN%SNRGO%E%E%H%FOAOOTKFLATSOOOOPMJN%CHDAAPMATTO%%T%ITETSOUPEKNAT%AILNETFD%TETAWS%MTKDNHAEULE%AEVOPM%%%OPEH%KNR%%TAAT%Y%MSOME%YEMG%K

DECRYPTED TEXT: POKEMON%TOWER%DEFENSE%YOUR%MISSION%IN%THIS%FUN%STRATEGY%TOWER%DEFENSE%GAME%IS%TO%HELP%PROFESSOR%OAK%TO%STOP%ATTACKS%OF%WILD%RATTATA.%SET%OUT%ON%YOUR%OWN%POKEMON%JOURNEY,%TO%CATCH%AND%TRAIN%ALL%POKEMON%AND%TRY%TO%SOLVE%THE%MYSTERY%BEHIND%THESE%ATTACKS.%YOU%MUST%PLACE%POKEMON%CHARACTERS%STRATEGICALLY%ON%THE%BATTLEFIELD%SO%THAT%THEY%STOP%ALL%WAVES%OF%ENEMY%ATTACKER%DURING%THE%BATTLE%YOU%WILL%LEVEL%UP%AND%EVOLVE%YOUR%POKEMON.%YOU%CAN%ALSO%CAPTURE%OTHER%%%POKEMON%DURING%THE%BATTLE%AND%ADD%THEM%TO%YOUR%TEAM.%USE%YOUR%MOUSE%TO%PLAY%THE%GAME.%GOOD%LUCK%%

============================================================

```

## Testing the code

- To test with custom plain text edit the `plain-text.txt` file and run `make` command.
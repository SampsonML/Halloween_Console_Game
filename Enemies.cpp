//
// Created by matt on 20/01/19.
//

#include "Enemies.h"


// An enemy class, to print the type of enemy you would like, just in main.cpp type Enemy("SOME_CREATURENAME).creature

Enemies:: Enemies(std:: string Creature){

    if (Creature == "Spider"){
        std:: cout << R"(
            (
               )
              (
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/
)" << std:: endl;
    }
    if (Creature == "Wolf"){
        std:: cout << R"(
                        ,     ,
                        |\---/|
                       /  , , |
                  __.-'|  / \ /
         __ ___.-'        ._O|
      .-'  '        :      _/
     / ,    .        .     |
    :  ;    :        :   _/
    |  |   .'     __:   /
    |  :   /'----'| \  |
    \  |\  |      | /| |
     '.'| /       || \ |
     | /|.'       '.l \\_
     || ||             '-'
     '-''-'
)" << std:: endl;
    }
    if (Creature == "Skeleton"){
        std:: cout << R"(
                              _.--""-._
  .                         ."         ".
 / \    ,^.         /(     Y             |      )\
/   `---. |--'\    (  \__..'--   -   -- -'""-.-'  )
|        :|    `>   '.     l_..-------.._l      .'
|      __l;__ .'      "-.__.||_.-'v'-._||`"----"
 \  .-' | |  `              l._       _.'
  \/    | |                   l`^^'^^'j
        | |                _   \_____/     _
        j |               l `--__)-'(__.--' |
        | |               | /`---``-----'"1 |  ,-----.
        | |               )/  `--' '---'   \'-'  ___  `-.
        | |              //  `-'  '`----'  /  ,-'   I`.  \
      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \
     '._' / \         _/(   `/   )- ---' ;  /__.J   L.__.\ :
      `._;/7(-.......'  /        ) (     |  |            | |
      `._;l _'--------_/        )-'/     :  |___.    _._./ ;
        | |                 .__ )-'\  __  \  \  I   1   / /
        `-'                /   `-\-(-'   \ \  `.|   | ,' /
                           \__  `-'    __/  `-. `---'',-'
                              )-._.-- (        `-----'
                             )(  l\ o ('..-.
                       _..--' _'-' '--'.-. |
                __,,-'' _,,-''            \ \
               f'. _,,-'                   \ \
              ()--  |                       \ \
                \.  |                       /  \
                  \ \                      |._  |
                   \ \                     |  ()|
                    \ \                     \  /
                     ) `-.                   | |
                    // .__)                  | |
                 _.//7'                      | |
               '---'                         j_| `
                                            (| |
                                             |  \
                                             |lllj
                                             |||||
)" << std:: endl;
    }
    if (Creature == "Dragon"){
        std:: cout << R"(
                 /           /
                /' .,,,,  ./
               /';'     ,/
              / /   ,,//,`'`
             ( ,, '_,  ,,,' ``
             |    /@  ,,, ;" `
            /    .   ,''/' `,``
           /   .     ./, `,, ` ;
        ,./  .   ,-,',` ,,/''\,'
       |   /; ./,,'`,,'' |   |
       |     /   ','    /    |
        \___/'   '     |     |
          `,,'  |      /     `\
               /      |        ~\
              '       (
             :
            ; .         \--
          :   \         ;
)" << std:: endl;
    }

    if (Creature == "Pumpkin"){
        std:: cout << R"(
                                                 ,---._
                                        ,~~,-._  `._
                                         v'~   `-.  `.
                                              _,- ~.  \
                                            .'  ,--`.  `\_
                                            V-'~ ,'~~~`-. `-.
                                ___             /_/~~~) ` `. `._
                       ____,---'   ;            V     `.__ `--, `;
                        `-._    ;  `.                ____)       :
                            `.;  ; .'              ,'        _    |
                             ; |   ;              ,';'~~~`--' `;  :
                            ,': .-'               `,'  __ __   :  |
                            )_  `-, ___     __        (__:__)   ; ;
                       _,---. \___,'` ~`---;  `-.       |||    ;  ;
                   _,-/   :;     !   `     `|    `-.   |~~~~|   ; :
               _,-' /~   .,'  ;  !!  `..    ``.    `.  :    ;  | :
             ,'  ,-'    .;   `; !!   _,'-' ,--._    ====\__/===: `.
           .'  ,-'   ,--.  ~~`-. !!  ~    ,'    `     `./  \   |  |
          .'  :;   ,'    \        !: .   ;--.__   `;.  |. ~.|   : ;
         .'  ,;    ' ,-'~~`-.     ,!  ;-'     #;   `;. \____/  : `.
        .'  ,;      /__      `-._,'!!( _(0'~~`-'    `;.  `.     ; ;
       .'  ,;    ,'    `---._(0))  !! ~   _,-,        `;  `.   ;  :
       ;  ,;    ,' ;;-.__,-._~~~   !!__,--::::|.      `;:  :   `; )
       ;  :|   ,'  ;/;;; :::;;;;----'|:: |::;\/#.      `;  |    ) ;
       :  |:  ,'  ,' :/  :;; \/))):;;::/  ::' ##:      ;;  ;    ; |
       |  :|  :;  :      `'    \/ \/ `'   `'  ##;      ;  .'  ,'  ;
       :  |;  || .'        ;\.   ____ __,--._ ##;     ;' .'--'   ;
   _,--`. `.  :: `./;   /\/;:;,-'    `-.     `--.__     .'~   ,'~
  /     ;. `; ``. :::;\;.-'~~`./~~\/\ ..    _  :::  --. ' ,-'~
 /    .  `. `; `   ~~~ ;~      ~~~~~~`--.__~~`-. :::   ) ~
/'    ;`--`. `. `.    :;      `;       ;   `---`._    ,'
`.  \/      `-.` `_,_ `:,-'-. `.      :_,_    ;   `--'
 `.  `.        ` (___)-: ( ) :--,-'- -(___),'~~~`.
  {_  `.               `.___.' ( ; ;)      :((:)):
    `.  `                       `--'       `.___.'
      `. `.                 ;;:::;
       `-  `.              ;;;. .;
         `-. `.__        \\;;; - ;; //
            `. ` `--..___ \\,--v-, //
              `--._   ~~~~~`)____(//
                   )    ~~   ~~~~~~;
                   `.    ~~  ------;
                    `.~~_   ______,'
                     `. `.--';: |:
                      ;  `. Cc; Cc
                      `.  ;  __
                       `. `-'  ~\
                        `-.__,--'~
)" << std:: endl;
    }

}
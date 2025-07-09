#include <map>
#include <algorithm>
#include <random>
#include <iostream>
#include <string>


#include "game.hpp"
#include "playership.hpp"   
#include "bullet.hpp"
#include "impact.hpp"
#include <fstream>

#include "raygui.h"
#include "raymath.h"    


using namespace std;

vector<string>oneLetterWords = {
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
};

vector <string>twoLetterWords = {
    "an","he","hi","my","oh","TV","us"
};

vector<string>threeLetterWords = {
"add","age","ago","air","ant","arm","art","ate","bad","bag","ban","bat","bed","box","boy","bus","but","buy","cap","car","cat","cow","cry","cup","dad","dam","day","did","die","dig","dog","dry","due","ear","eat","eel","egg","eye","far","few","fly","fox","fur","god","got","gun","gym","had","ham","has","hat","hey","him","hot","hug","ice","ill","ink","its","job","joy","kit","law","lay","leg","lie","log","man","map","men","met","mix","mom","mop","mug","net","new","nod","not","oil","our","own","pan","pay","pen","per","pet","pie","pot","ran","raw","red","sad","saw","sea","she","shy","sit","six","ski","sky","son","sun","tag","tap","tax","tea","ten","tie","toe","ton","top","toy","try","two","vet","via","war","was","wet","why","won","wow","zoo",
};
vector<string>fourLetterWords = {
"able","area","aunt","baby","back","bake","ball","band","bang","bead","bean","bear","beat","beef","been","bell","belt","bike","bill","bird","blog","blue","body","bomb","book","born","both","bowl","bury","busy","cafe","cake","came","camp","card","care","cart","case","chef","chop","city","clap","club","coal","coat","coin","cold","comb","cook","cool","core","cork","corn","cute","dark","data","date","dead","dear","desk","dome","done","door","down","draw","drop","drum","each","earn","easy","else","ever","fact","fail","feed","feel","feet","fell","fill","film","fish","five","flat","flip","fold","folk","food","foot","form","four","frog","gate","gave","gear","gift","girl","give","glad","glue","goal","grew","hair","half","hand","hang","harm","head","heat","held","hero","hers","hold","hole","host","hunt","hurt","idea","item","jail","join","July","jump","June","kept","king","knee","knew","know","lake","lamp","land","late","lazy","leaf","less","lion","lose","loss","lost","loud","luck","main","math","mean","meat","menu","mild","milk","mind","miss","moon","must","neck","news","nice","nine","noon","nose","once","only","oops","ours","pack","page","paid","pair","part","past","pear","pick","pine","pink","plan","plum","pool","poor","pork","post","pour","pray","prop","puck","pull","pure","quiz","rain","ramp","real","rice","rich","ride","ring","rise","road","rode","role","room","root","rose","safe","salt","same","seem","seen","sell","send","shoe","shot","side","sign","sing","site","size","slow","snow","sock","soda","soft","sold","song","soon","sort","soup","sour","spot","stab","star","stir","such","suit","surf","swim","talk","tall","task","taxi","team","teen","tell","tent","term","text","than","them","they","thin","tiny","told","took","tour","town","trap","tree","trip","true","turf","type","upon","vary","very","wage","wait","wake","wall","want","warm","wash","wave","weak","wear","week","went","were","wide","wife","wind","wing","wise","woke","wolf","wool","wrap","your","zero",
};
vector<string>fiveLetterWords = {
"above","actor","adult","again","agree","album","alien","alive","along","among","angry","anime","apple","April","apron","arrow","Asian","aside","avoid","bacon","baker","beach","began","begin","below","bench","berry","black","block","boots","bored","brave","bread","break","breed","brown","brush","build","cacti","camel","candy","carry","catch","cause","cedar","chair","charm","chart","chase","cheap","check","cheer","child","China","chose","clear","clerk","climb","clock","close","cloth","cloud","comic","count","court","cover","cream","creep","crept","crime","cross","curry","daily","death","dirty","donut","drama","drawn","dream","dress","early","Earth","eight","Elfie","empty","enjoy","enter","essay","event","favor","fever","field","fifth","fifty","final","flood","floor","flour","force","forty","frank","fresh","fried","front","fruit","funny","genre","glass","globe","glove","goods","grape","graph","gravy","green","grill","group","grown","guest","guide","happy","heart","heavy","Hindi","horse","hotel","house","human","humid","ideal","image","India","Italy","Japan","jeans","jewel","judge","juice","Kenya","knock","known","koala","Korea","labor","later","learn","least","lemon","limit","linen","liter","lives","local","lucky","lunch","maple","match","maybe","mayor","meant","melon","meter","mixed","model","mommy","money","month","mouse","mouth","movie","music","niece","night","ninth","noisy","nurse","ocean","offer","often","onion","order","owner","paint","panda","pants","party","paste","patty","peace","peach","phone","photo","piano","piece","pilot","pizza","plant","plate","point","price","print","proud","puppy","queen","quiet","quite","rainy","raise","ramen","reach","ready","relax","relay","reply","river","round","rugby","ruler","salad","salty","sauce","scarf","scene","scold","score","serve","seven","shade","shall","shape","share","shark","sheep","shell","shirt","shock","shoot","short","shout","shown","since","sixth","sixty","skate","skill","skirt","sleep","slept","slide","smart","smoke","snack","snake","snowy","solve","Spain","speak","speed","spell","spend","spent","spicy","spill","spoke","sport","staff","stage","stair","steak","steam","stick","still","stood","store","storm","story","straw","study","sunny","sword","table","taste","tasty","teach","teeth","tenth","their","there","thick","thing","those","three","tiger","tired","today","tooth","topic","touch","tough","towel","trade","trail","train","trick","trust","twice","uncle","until","upset","value","vegan","video","visit","voice","water","weigh","whale","where","while","white","whole","whose","windy","woman","world","worry","worth","wrote","young","yours","youth","zebra",
};
vector<string>sixLetterWords = {
"abroad","accept","across","action","active","adjust","advice","afraid","Africa","almost","always","amount","animal","annual","anyone","anyway","appear","Arabic","arrest","arrive","artist","assist","August","author","autumn","banana","basket","batter","beauty","became","behind","belong","beyond","bitter","blouse","border","boring","borrow","bother","bottle","bottom","bought","Brazil","bridge","bright","Buddha","bullet","butter","camera","Canada","candle","cannot","career","castle","casual","caught","center","chance","charge","cheese","cherry","choice","choose","chorus","chosen","church","client","cloudy","coffee","colony","common","cookie","corner","cotton","couple","course","cousin","crater","crayon","create","crisis","crispy","crosse","custom","damage","danger","debate","decent","decide","depend","desert","device","dinner","doctor","dollar","donate","double","driver","dugong","during","easily","effort","eighth","eighty","eleven","energy","enough","ensure","eraser","escape","ethnic","except","expect","export","extend","fabric","famous","farmer","faucet","finish","flavor","flight","floral","flower","follow","forest","forget","former","fourth","France","freely","French","Friday","friend","garden","gather","gender","gentle","German","global","golden","ground","growth","guitar","handle","happen","hidden","hiking","holder","honest","humane","hunger","hungry","ignore","impact","import","injure","invent","invite","island","jacket","jungle","kitten","Korean","lawyer","leader","legacy","lesson","listen","living","locate","lonely","manner","marble","marker","market","medium","member","memory","Mexico","middle","mighty","minute","mirror","moment","Monday","monkey","mosque","mother","museum","myself","narrow","nation","native","nature","nearby","neatly","nephew","ninety","noodle","object","office","omelet","origin","oxygen","pajama","palace","pardon","parent","pencil","people","period","person","picnic","pillow","player","please","pocket","poster","potato","pretty","public","purple","pursue","Quebec","rabbit","racket","reader","reason","recipe","reduce","region","reject","relate","remind","remove","repeat","report","result","retell","return","review","ritual","runner","Russia","safely","sandal","scared","school","scroll","season","select","server","setter","severe","shadow","shorts","should","shower","shrine","silver","singer","sister","skiing","sleepy","slowly","soccer","speech","spider","spiker","spirit","street","strict","string","strong","studio","sudden","suffer","summer","Sunday","sunset","supply","survey","symbol","talent","taught","temple","tennis","theirs","thirty","threat","ticket","tomato","toward","travel","trivia","Turkey","twelve","twenty","unfair","unfold","unique","unused","useful","vendor","violin","wallet","weakly","weapon","weight","widely","window","winner","winter","wisdom","wooden","worker","writer","yellow","zipper",
};
vector<string>sevenLetterWords = {
"ability","African","against","airport","already","amazing","America","ancient","annoyed","anymore","appoint","article","athlete","attract","baggage","barrier","bathtub","battery","because","believe","beloved","between","bicycle","braille","brother","brought","cabbage","camping","captain","careful","cartoon","century","cheetah","chicken","citizen","classic","cleanup","clearly","climate","closing","clothes","collect","comfort","comment","commute","company","compare","concern","concert","connect","consist","contact","content","contest","control","cooking","country","courage","crowded","cuisine","culture","curling","cushion","dancing","deliver","Denmark","dessert","destroy","develop","display","diverse","dolphin","drought","elderly","emperor","ethical","evening","example","excited","explain","express","extinct","factory","fashion","feather","feature","feeling","fifteen","filling","finally","fishing","folding","foreign","forever","forward","founder","freedom","gallery","garbage","general","Germany","giraffe","glacier","glasses","goodbye","gorilla","grandma","grandpa","greatly","habitat","hallway","handbag","hectare","helpful","herself","history","holiday","however","hundred","hunting","Iceland","illegal","imagine","include","inspire","instant","instead","Italian","January","justice","kitchen","knitted","leather","lettuce","library","logging","lullaby","measure","message","million","mistake","morally","morning","musical","natural","naughty","nervous","nothing","nuclear","nursery","October","octopus","opening","opinion","organic","pancake","parfait","parking","pastime","patient","penguin","percent","perfect","perform","picture","plastic","playful","pollute","popular","pottery","poutine","poverty","prepare","present","printer","problem","produce","product","program","promote","protect","provide","publish","quality","quarter","quickly","quietly","rainbow","rapidly","reading","realize","receive","recycle","reflect","require","respect","Russian","sausage","savanna","science","seafood","selfish","serious","service","seventh","seventy","several","shelter","shortly","silence","sixteen","sneaker","society","someday","someone","Spanish","speaker","special","species","stadium","stapler","starter","station","strange","student","stylish","subject","sunrise","support","survive","sweater","Taliban","teacher","texture","theater","thermal","thirsty","tightly","topping","tornado","tourism","tourist","trouble","tsunami","Tuesday","Turkish","twelfth","typhoon","Ukraine","uniform","unlucky","unusual","usually","utilize","variety","various","village","visitor","weather","website","weekday","weekend","Western","wetland","whistle","without","working","worried",
};
vector<string>eightLetterWords = {
"activity","actually","addition","although","American","announce","anything","anywhere","aquarium","backpack","baseball","birthday","building","campaign","campfire","Canadian","careless","ceremony","cheerful","chemical","chestnut","children","clothing","colorful","comedian","computer","consumer","continue","creature","cultural","customer","darkness","daughter","December","decision","delicate","delivery","designer","diligent","disabled","disagree","disaster","discover","downtown","economic","Egyptian","eighteen","elephant","elevator","eleventh","employee","entirely","entrance","envelope","equality","eruption","everyone","exchange","exciting","facility","February","feedback","festival","firework","firmness","follower","formally","fourteen","friendly","frighten","gardener","generous","goldfish","guidance","handrail","headache","heritage","homestay","hometown","homework","hospital","industry","internet","inventor","kindness","lacrosse","landmark","language","material","medicine","midnight","mischief","moreover","mountain","mushroom","national","necklace","negative","neighbor","nineteen","northern","notebook","November","nowadays","optional","ordinary","original","outgoing","painting","Pakistan","peaceful","position","positive","possible","powerful","precious","prepared","probably","progress","prohibit","question","recently","recorder","recovery","recycled","regional","relieved","remember","research","resident","resource","restroom","reusable","sandwich","Saturday","schedule","scissors","sentence","shopping","shoulder","sidewalk","sleeping","softball","solution","sometime","souvenir","squirrel","standard","straight","strategy","strength","struggle","suddenly","sunshine","surround","survival","swimming","teammate","terrible","textbook","Thailand","thirteen","thousand","Thursday","together","tolerant","tomorrow","traveler","umbrella","vacation","violence","whatever","wildlife","yourself",
};
vector<string>nineLetterWords = {
"accessory","according","advantage","adventure","afternoon","animation","apartment","Argentina","astronaut","attracted","Australia","automatic","available","badminton","beautiful","beginning","bookstore","breakfast","brilliant","brutality","butterfly","cafeteria","carefully","carpenter","castanets","celebrate","challenge","character","childhood","chocolate","chopstick","Christian","Christmas","classmate","classroom","cloudless","colorless","community","condition","cooperate","dangerous","dedicated","delicious","developed","difficult","direction","disappear","diversity","dodgeball","easygoing","ecosystem","education","effective","emergency","encourage","energetic","equipment","exception","existence","expansion","expensive","extensive","extremist","fantastic","fifteenth","foreigner","Halloween","hamburger","harmonica","ignorance","impatient","important","Indonesia","influence","injustice","introduce","invention","kilometer","landscape","landslide","migratory","necessary","newspaper","operation","oversleep","performer","pesticide","pictogram","pineapple","pollution","prejudice","president","professor","radiation","rainwater","recognize","recommend","rectangle","recycling","remaining","renewable","represent","riverbank","scientist","selection","September","seventeen","sincerely","Singapore","situation","sixteenth","something","sometimes","spaghetti","spiritual","structure","sunscreen","surprised","talkative","technique","terrorism","terrorist","therefore","thirtieth","thrilling","toothache","touchless","tradition","twentieth","universal","unspoiled","variation","vegetable","volunteer","warehouse","Wednesday","wonderful","worldwide","xylophone","yesterday",
};
vector<string>tenLetterWords = {
"accessible","adjustable","affordable","aftershock","artificial","Azerbaijan","basketball","bestseller","campground","cartoonist","categorize","collection","compulsory","conclusion","conference","convenient","creativity","critically","definitely","developing","dictionary","difficulty","discussion","distribute","earthquake","eighteenth","electronic","endangered","especially","evacuation","eventually","everything","extinction","fourteenth","government","historical","illiteracy","illiterate","importance","impossible","impressive","indigenous","Indonesian","inequality","ingredient","innovation","instrument","interested","leadership","management","mayonnaise","mechanical","nineteenth","originally","photograph","population","Portuguese","prefecture","production","protection","reasonable","regardless","relatively","researcher","respectful","restaurant","sanitation","schoolyard","smartphone","stationery","strawberry","sunglasses","sweatshirt","technology","thirteenth","throughout","understand","understood","university","volleyball","vulnerable","watermelon","wheelchair","wilderness",
};
vector<string>elavenLetterWords = {
"Afghanistan","architecture","arrangement","biologically","broadcasting","calligraphy","caterpillar","colorfulness","communicate","communication","confectioner","consumption","convenience","countryside","deforestation","desertification","destruction","destructive","development","disappointed","discrimination","educational","electricity","embarrassed","environment","environmental","examination","extinguisher","furthermore","grandfather","grandmother","grandparent","hairstylist","handcrafted","handkerchief","harmoniously","illustration","imagination","independence","information","infrastructure","institution","instruction","interdependent","interesting","international","internationally","manufacturer","opportunity","overhunting","partnership","performance","personality","photographer","photography","polyurethane","prehistoric","presentation","recommended","relationship","reservation","responsible","seventeenth","snowboarding","stomachache","subtropical","supermarket","supervision","sustainable","thunderstorm","timekeeping","traditional","transportation",
};

// boss level words
vector<string> twelveLetterWords = {
    "considerable", "extraordinary", "unbelievable", "unemployment",
    "overextended", "inflammation", "contradicted", "relationship"
};

vector<string> thirteenLetterWords = {
    "consideration", "multinational", "underestimate", "consciousness",
    "understanding", "questionnaire", "transformation"
};

vector<string> fourteenLetterWords = {
    "misunderstand", "thermodynamic", "interdependent", "uncontrollably",
    "counterattack", "representative", "photosynthesis"
};

vector<string> fifteenLetterWords = {
    "disappointment", "congratulations", "consciousnesses",
    "disorganization", "misinformation", "underprivileged"
};

vector<string> sixteenLetterWords = {
    "anthropological", "counterproductive", "intercontinental",
    "oversimplifying", "environmentalist"
};

vector<string> seventeenLetterWords = {
    "institutionalized", "counterintuitive", "individualization",
    "disenfranchising"
};

vector<string> eighteenLetterWords = {
    "misinterpretation", "overspecification", "overcomplication",
    "differentiations"
};

vector<string> nineteenLetterWords = {
    "disenfranchisement", "hyperintellectuals", "commercialization"
};

vector<string> twentyLetterWords = {
    "mischaracterization", "internationalization", "overindustrialization"
};

vector<string> veryLongWords = {
    "counterrevolutionaries", "overintellectualizing", "antidisestablishmentarianism" // 28 letters
};

map<int, vector<string>>levelWord =
{
    {1,twoLetterWords},
    {2,threeLetterWords},
    {3,fourLetterWords},
    {4,fiveLetterWords},
    {5,sixLetterWords},
    {6,sevenLetterWords},
    {7,eightLetterWords},
    {8,nineLetterWords},
    {9,tenLetterWords},
    {10,elavenLetterWords},
};

map<int, vector<string>>bossLevelWord =
{
    {1,twelveLetterWords},
    {2,thirteenLetterWords},
    {3,fourteenLetterWords},
    {4,fifteenLetterWords},
    {5,sixteenLetterWords},
    {6,seventeenLetterWords},
    {7,eighteenLetterWords},
    {8,nineteenLetterWords},
    {9,twentyLetterWords},
    {10,veryLongWords},
};


Game::Game(Font f)
{
    this->font = f;
    this->gameState = MAIN_MENU;
    this->levelStartTime = 0;
    this->levelDelay = 3.0f;
    this->music = LoadMusicStream("Sounds/background_music.ogg");
    this->shouldClose = false;
    this->isPaused = false;
    this-> menuSelection = 0;
    this-> totalMenuItems = 2;
    PlayMusicStream(music);
    SetMusicVolume(music, 0.5f);
    InitGame();
}

Game::~Game()
{
    UnloadFont(font);
    UnloadTexture(explosionTexture);
    UnloadTexture(impactTexture);
    UnloadTexture(powerUpTexture);
    UnloadMusicStream(music);
    UnloadSound(levelCompleteSound);
    UnloadSound(explosionSound);
    UnloadSound(errorSound);
    UnloadSound(powerUpSound);
    UnloadSound(gameOverSound);
}

void Game::Initialize()
{
    bossIsDead = false;
    bossCreated = false;
    score = 0;
    wordTyped = 0;
    timeSpentTyping = 0;
    typingStartTime = 0;
    wpm = 0;
    totalKeyStrokes = 0;
    successfulKeyStrokes = 0;
    numWordsWithoutMiss = 0;
    canPowerUp = true;
    hasMissTyped = false;
    powerUps = 0;
    highScore = LoadHighScore();
    lives = 3;
    lastDeathTime = 0.0f;
    level = 1;
    target_idx = -1;
    playership.position.x = GetScreenWidth() / 2;
    playership.position.y = GetScreenHeight() - 100;
}


void Game::LoadAssets()
{
    powerUpTexture = LoadTexture("assets/ExplosiveBarrel.png");
    explosionTexture = LoadTexture("assets/explosion.png");
    impactTexture = LoadTexture("assets/explosion-sheet.png");
    explosionSound = LoadSound("Sounds/explosion.ogg");
    impactSound = LoadSound("Sounds/NenadSimic - Muffled Distant Explosion.wav");
    errorSound = LoadSound("Sounds/caught.wav");
    levelCompleteSound = LoadSound("Sounds/newthingget.ogg");
    powerUpSound = LoadSound("Sounds/Win_sound.wav");
}

void Game::InitGame()
{
    Initialize();
    LoadAssets();
    for ( auto& [level, words] : levelWord )
    {
        shuffle(words.begin(), words.end(), default_random_engine(GetTime() * 1000));
    }
    shuffle(oneLetterWords.begin(), oneLetterWords.end(), default_random_engine(GetTime() * 1000));

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(DARKGRAY));
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt(LIGHTGRAY));
}

void Game::Draw()
{
    if ( gameState == GAME_OVER )
    {
        ShowResult(50);
        ShowWords("GAME OVER", 250);
        const int buttonWidth = 200;
        const int buttonHeight = 50;
        const int x = GetScreenWidth() / 2 - buttonWidth / 2;
        const int y = GetScreenHeight() - 100 - buttonHeight;
        Rectangle startBtn = { ( float )x,( float )y,( float )buttonWidth,( float )buttonHeight };
        Rectangle quitBtn = { x,y + 70,buttonWidth,buttonHeight };


        Color defaultBorder = GetColor(GuiGetStyle(BUTTON, BORDER_COLOR_NORMAL));
        Color defaultBase = GetColor(GuiGetStyle(BUTTON, BASE_COLOR_NORMAL));
        Color defaultText = GetColor(GuiGetStyle(BUTTON, TEXT_COLOR_NORMAL));


        Color hoverBorder = GetColor(GuiGetStyle(BUTTON, BORDER_COLOR_FOCUSED));
        Color hoverBase = GetColor(GuiGetStyle(BUTTON, BASE_COLOR_FOCUSED));
        Color hoverText = GetColor(GuiGetStyle(BUTTON, TEXT_COLOR_FOCUSED));


        if ( menuSelection == 0 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }

        bool startPressed = GuiButton(startBtn, "Start New Game") || ( menuSelection == 0 && IsKeyPressed(KEY_ENTER) );


        // resent style


        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( menuSelection == 1 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }

        bool quitPressed = GuiButton(quitBtn, "Quit") || ( menuSelection == 1 && IsKeyPressed(KEY_ENTER) );

        // reset style
        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( startPressed )
        {
            playership.alive = true;
            InitGame();
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        if ( quitPressed ) {
            shouldClose = true;
        }
        return;

    }
    for ( auto& explosion : explosions )
    {
        explosion.Draw();
    }
    for ( auto& impact : impacts )
    {
        impact.Draw();
    }
    if ( gameState == MAIN_MENU )
    {
        const int buttonWidth = 200;
        const int buttonHeight = 50;
        const int x = GetScreenWidth() / 2 - buttonWidth / 2;
        const int y = GetScreenHeight() / 2 - buttonHeight;
        DrawText("KEYWARS", GetScreenWidth() / 2 - MeasureText("KEYWARS", 60) / 2, 100, 60, WHITE);

        Rectangle startBtn = { ( float )x,( float )y,( float )buttonWidth,( float )buttonHeight };
        Rectangle quitBtn = { ( float )x,( float )y + 70.0f,( float )buttonWidth,( float )buttonHeight };


        Color defaultBorder = GetColor(GuiGetStyle(BUTTON, BORDER_COLOR_NORMAL));
        Color defaultBase = GetColor(GuiGetStyle(BUTTON, BASE_COLOR_NORMAL));
        Color defaultText = GetColor(GuiGetStyle(BUTTON, TEXT_COLOR_NORMAL));


        Color hoverBorder = GetColor(GuiGetStyle(BUTTON, BORDER_COLOR_FOCUSED));
        Color hoverBase = GetColor(GuiGetStyle(BUTTON, BASE_COLOR_FOCUSED));
        Color hoverText = GetColor(GuiGetStyle(BUTTON, TEXT_COLOR_FOCUSED));


        if ( menuSelection == 0 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }

        bool startPressed = GuiButton(startBtn, "Start Game") || ( menuSelection == 0 && IsKeyPressed(KEY_ENTER) );


        // resent style


        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( menuSelection == 1 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }

        bool quitPressed = GuiButton(quitBtn, "Quit") || ( menuSelection == 1 && IsKeyPressed(KEY_ENTER) );

        // reset style
        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( startPressed ) {
            InitGame();
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        if ( quitPressed ) {
            shouldClose = true;
        }
        return;
    }
    if ( gameState == PLAYING || gameState == PAUSED )
    {
        playership.Draw();
        float x = 0 + playership.image.width / 2;
        float y = GetScreenHeight() - playership.image.height;
        for ( int i = 0; i + 1 < lives; i++ )
        {
            Vector2 pos = { x,y };
            DrawTextureV(playership.image, pos, WHITE);
            x += playership.image.width + 10;
        }
        for ( int i = 0; i < ( int )wordships.size(); i++ )
        {
            bool isTarget = isValid(target_idx) && ( i == target_idx );
            wordships[i].Draw(isTarget);
        }

        for ( auto& bullet : playership.bullets )
        {
            bullet.Draw();
        }
        for ( auto& bullet : playership.powerUpBullets )
        {
            bullet.Draw();
        }

        ShowPowerUps();
        ShowProgressbar();
    }


    if ( gameState == LEVEL_COMPLETED )
    {
        // show score and accuracy
        ShowResult(0);
        string str = "LEVEL COMPLETE";
        ShowWords(str, 150);
        return;
    }
    if ( gameState == SHOW_NEXT_LEVEL )
    {
        string str = "LEVEL " + to_string(level);
        ShowWords(str, 0);
        return;
    }

}

void Game::Update()
{
    HandleTyping();
    if ( gameState == PAUSED )return;
    UpdateMusicStream(music);
    if ( gameState == MAIN_MENU || gameState == GAME_OVER )
    {
        if ( IsKeyPressed(KEY_DOWN) )
        {
            menuSelection = ( menuSelection + 1 ) % totalMenuItems;
        }
        if ( IsKeyPressed(KEY_UP) )
        {
            menuSelection = ( ( menuSelection - 1 ) + totalMenuItems ) % totalMenuItems;
        }
    }
    for ( auto& bullet : playership.bullets )
    {
        bullet.Update();
    }
    for ( auto& bullet : playership.powerUpBullets )
    {
        bullet.Update();
    }
    for ( auto& impact : impacts )
    {
        impact.Update();
    }
    for ( auto& explosion : explosions )
    {
        explosion.Update();
    }
    for ( auto& word : wordships )
    {
        word.Move();
    }
    CheckCollisions();
    DeleteInactiveBullets();
    DeleteInactivePowerdUpBullets();
    DeleteInactiveWordShips();
    DeleteFinishedExplosions();
    DeleteInactiveImpacts();


    if ( gameState == PLAYING && !playership.alive )
    {
        if ( lives > 0 )
        {
            if ( GetTime() - lastDeathTime > 0.5f )
            {
                playership.alive = true;
                playership.position.x = GetScreenWidth() / 2;
                playership.position.y = GetScreenHeight() - 100;
            }
        }
        else
        {

            for ( auto& wordship : wordships )
            {
                wordship.alive = false;
            }
            gameState = GAME_OVER;
            return;
        }

    }
    if ( gameState == PLAYING && wordships.empty() )
    {
        if ( bossIsDead )
        {
            PlaySound(levelCompleteSound);
            if ( numWordsWithoutMiss >= level * 5 )
            {
                score += ( level * 10 );
            }
            if ( score > highScore )
            {
                SaveHighScore(score);
                highScore = LoadHighScore();
            }
            bossIsDead = false;
            bossCreated = false;
            gameState = LEVEL_COMPLETED;
            timeSpentTyping += ( GetTime() - typingStartTime );
            typingStartTime = -1;
            levelStartTime = GetTime();
            return;
        }
        else
        {
            // create boss word
            if ( !bossCreated )
            {
                int boss_level = min(10, level);
                int boss_idx = GetRandomValue(0, ( int )bossLevelWord[boss_level].size() - 1);
                std::string boss_word = bossLevelWord[boss_level][boss_idx];
                int offset = GetRandomValue(0, GetScreenWidth() / 2 - 200);
                int sign = GetRandomValue(0, 1) == 0 ? -1 : 1;
                offset *= sign;
                int posX = ( GetScreenWidth() / 2 ) + offset;
                int posY = - 10;
                Vector2 pos = { posX,posY };
                wordships.push_back(WordShip(font, pos, boss_word, level, true, false, playership.position));
                bossCreated = true;
            }

            return;
        }

    }
    if ( gameState == LEVEL_COMPLETED )
    {
        if ( GetTime() - levelStartTime > levelDelay )
        {
            if ( score > highScore )
            {
                SaveHighScore(score);
                highScore = LoadHighScore();
            }
            level++;
            canPowerUp = true;
            hasMissTyped = false;
            bossIsDead = false;
            numWordsWithoutMiss = 0;
            target_idx = -1;
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        return;
    }
    if ( gameState == SHOW_NEXT_LEVEL )
    {
        if ( GetTime() - levelStartTime > 1.5f )
        {
            if ( score > highScore )
            {
                SaveHighScore(score);
                highScore = LoadHighScore();
            }
            target_idx = -1;
            wordships = CreateWordships();
            cout << "Words = " << wordships.size() << "\n";
            gameState = PLAYING;
        }
    }
}

void Game::CheckCollisions()
{
    if ( !isValid(target_idx) )
    {
        target_idx = -1;
    }
    if ( gameState == GAME_OVER )
    {
        target_idx = -1;
        return;
    }
    // bullets vs wordships

    for ( auto& bullet : playership.bullets )
    {
        if ( bullet.target && bullet.target->alive )
        {
            if ( CheckCollisionRecs(bullet.GetRect(), bullet.target->GetRect()) )
            {
                Vector2 hitPos = bullet.target->GetCenter();
                impacts.emplace_back(&impactTexture, hitPos);
                bullet.active = false;
                PlaySound(impactSound);
            }
        }

    }


    //wordships vs powered up bullets

    for ( auto& bullet : playership.powerUpBullets )
    {
        if ( bullet.target && bullet.target->alive )
        {
            if ( CheckCollisionRecs(bullet.GetRect(), bullet.target ->GetRect()) )
            {
                Vector2 explosionPos = bullet.target->GetCenter();
                explosions.emplace_back(&explosionTexture, explosionPos);
                PlaySound(explosionSound);
                if ( isValid(target_idx) && bullet.target->word == wordships[target_idx].word )
                {
                    target_idx = -1;
                }
                bullet.target->alive = false;
                if ( bullet.target->isBoss )
                {
                    bossIsDead = true;
                    CreateMiniWordShips(bullet.target->position, level);
                }
                bullet.active = false;
            }
        }
    }


    // wordship vs wordship
    for ( int i = 0; i < ( int )wordships.size(); i++ )
    {

        for ( int j = i + 1; j < ( int )wordships.size(); j++ )
        {
            if ( CheckCollisionRecs(wordships[i].GetRect(), wordships[j].GetRect()) )
            {
                Rectangle r1 = wordships[i].GetRect();
                Rectangle r2 = wordships[j].GetRect();

                float overlapX = min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x);
                float overlapY = min(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y);

                if ( overlapX > 0 && overlapY > 0 )
                {
                    if ( overlapX < overlapY )
                    {
                        wordships[i].position.x -= overlapX / 2;
                        wordships[j].position.x += overlapX / 2;
                    }
                    else
                    {
                        if ( !wordships[i].isMinionShip )
                        {
                            wordships[i].position.y -= overlapY / 2;
                        }
                        if ( !wordships[j].isMinionShip )
                        {
                            wordships[j].position.y += overlapY / 2;
                        }
                    }

                    if ( !wordships[i].isMinionShip && !wordships[j].isMinionShip )
                    {
                        swap(wordships[i].velocity.x, wordships[j].velocity.x);
                        swap(wordships[i].velocity.y, wordships[j].velocity.y);
                    }
                }
            }
        }
    }

    // wordship vs playership
    for ( auto& wordship : wordships )
    {
        if ( !wordship.alive ) continue;
        if ( CheckCollisionRecs(wordship.GetRect(), playership.GetRect()) )
        {
            lastDeathTime = GetTime();
            wordship.alive = false;
            // trigger explosion
            Vector2 explosionPos = { playership.position.x + playership.image.width / 2,playership.position.y };
            explosions.emplace_back(&explosionTexture, explosionPos);
            PlaySound(explosionSound);
            playership.alive = false;
            lives--;
            return;
        }
    }

}

bool Game::isValid(int idx)
{
    if ( idx < 0 || idx >= ( int )wordships.size() )return false;
    return ( wordships[idx].alive );
}

void Game::HandleTyping()
{
    if ( !isValid(target_idx) )
    {
        target_idx = -1;
    }
    if ( IsKeyPressed(KEY_SPACE) )
    {
        if ( gameState == PLAYING )
        {
            gameState = PAUSED;
            isPaused = true;
            return;
        }
        else if ( gameState == PAUSED )
        {
            gameState = PLAYING;
            isPaused = false;
            return;
        }
    }
    if ( isPaused || gameState != PLAYING )return;
    if ( ( IsKeyDown(KEY_TAB) && IsKeyPressed(KEY_ENTER) ) )
    {
        if ( powerUps > 0 )
        {
            ActivatePowerup();
            powerUps--;
        }
    }
    char typed = playership.Fire();
    if ( typed == '\0' )return;

    if ( isValid(target_idx) && !wordships[target_idx].alive )
    {
        target_idx = -1;
    }
    totalKeyStrokes++;
    if ( typingStartTime == -1 )
    {
        typingStartTime = GetTime();
    }
    if ( target_idx == -1 )
    {
        target_idx = GetTargetWordIdx(typed);
        if ( isValid(target_idx) )
        {
            if ( wordships[target_idx].word[wordships[target_idx].typedCount] == typed )
            {
                score++;
                successfulKeyStrokes++;
                PlaySound(playership.LaserSound);
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
                playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 40.0f, false));

                wordships[target_idx].typedCount++;

                if ( wordships[target_idx].typedCount >= ( int )wordships[target_idx].word.size() )
                {
                    // trigger explosion
                    if ( wordships[target_idx].isBoss )
                    {
                        bossIsDead = true;
                        // create mini wordships
                        Vector2 position = wordships[target_idx].position;
                        CreateMiniWordShips(position, level);

                    }
                    wordTyped ++;
                    Vector2 explosionPos = wordships[target_idx].GetCenter();
                    explosions.emplace_back(&explosionTexture, explosionPos);
                    PlaySound(explosionSound);
                    if ( !hasMissTyped )
                    {
                        ++numWordsWithoutMiss;
                        if ( numWordsWithoutMiss >= ( level + 4 + ( level / 2 ) ) && canPowerUp )
                        {
                            powerUps++;
                            PlaySound(powerUpSound);
                            canPowerUp = false;
                        }
                    }
                    hasMissTyped = false;
                    wordships[target_idx].alive = false;
                    target_idx = -1;
                }
            }
            else
            {
                PlaySound(errorSound);
                hasMissTyped = true;
                numWordsWithoutMiss = 0;
            }

        }
    }
    else
    {
        if ( isValid(target_idx) && wordships[target_idx].word[wordships[target_idx].typedCount] == typed )
        {
            score++;
            successfulKeyStrokes++;
            PlaySound(playership.LaserSound);
            wordships[target_idx].typedCount++;

            // matched. So fire a bullet towards the wordship

            Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
            playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 40.0f, false));

            if ( isValid(target_idx) && wordships[target_idx].typedCount >= ( int )wordships[target_idx].word.size() )
            {
                if ( wordships[target_idx].isBoss )
                {
                    bossIsDead = true;
                    Vector2 position = wordships[target_idx].position;
                    CreateMiniWordShips(position, level);
                }
                wordTyped ++;
                Vector2 explosionPos = wordships[target_idx].GetCenter();
                explosions.emplace_back(&explosionTexture, explosionPos);
                PlaySound(explosionSound);
                if ( !hasMissTyped )
                {
                    ++numWordsWithoutMiss;;
                    if ( numWordsWithoutMiss >= ( level + 4 + ( level / 2 ) ) && canPowerUp )
                    {
                        powerUps++;
                        PlaySound(powerUpSound);
                        canPowerUp = false;
                    }
                }
                hasMissTyped = false;
                wordships[target_idx].alive = false;
                target_idx = -1;
            }
        }
        else
        {
            PlaySound(errorSound);
            hasMissTyped = true;
            numWordsWithoutMiss = 0;
        }
    }
}

void Game::ShowResult(int yOffset)
{
    // Save current style values
    int prevTextSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    int prevTextSpacing = GuiGetStyle(DEFAULT, TEXT_SPACING);
    int prevLabelColor = GuiGetStyle(LABEL, TEXT_COLOR_NORMAL);
    int prevLabelBg = GuiGetStyle(LABEL, BASE_COLOR_NORMAL);

    // Apply styles for the result panel
    GuiSetStyle(DEFAULT, TEXT_SIZE, 28);
    GuiSetStyle(DEFAULT, TEXT_SPACING, 2);
    GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, ColorToInt(BLACK));
    GuiSetStyle(LABEL, BASE_COLOR_NORMAL, ColorToInt(DARKGRAY)); // Gives subtle background

    // Panel size and position
    float cardWidth = 300;
    float cardHeight = 280;
    float cardX = GetScreenWidth() / 2.0f - cardWidth / 2.0f;
    float cardY = ( GetScreenHeight() / 2.0f - cardHeight / 2.0f ) + 100 - yOffset;
    Rectangle cardRect = { cardX, cardY, cardWidth, cardHeight };
    GuiPanel(cardRect, "");

    // Score and accuracy
    string scoreStr = "Score: " + to_string(score);
    int acc = ( totalKeyStrokes > 0 ) ? ( ( successfulKeyStrokes * 100 ) / totalKeyStrokes ) : 0;
    string accuracyStr = "Accuracy: " + to_string(acc) + "%";
    string highScoreStr = "High Score : " + to_string(highScore);

    // wpm

    wpm = ( wordTyped * 60 ) / timeSpentTyping;
    string wpmStr = "WPM : " + to_string(wpm);

    float padding = 20;
    Vector2 scorePos = { cardX + padding, cardY + padding + 20 };
    Vector2 highScorePos = { cardX + padding, cardY + padding + 80 };
    Vector2 accPos = { cardX + padding, cardY + padding + 140 };
    Vector2 wpmPos = { cardX + padding, cardY + padding + 200 };
    GuiLabel({ scorePos.x, scorePos.y, cardWidth - 2 * padding, 30 }, scoreStr.c_str());
    GuiLabel({ highScorePos.x, highScorePos.y, cardWidth - 2 * padding, 30 }, highScoreStr.c_str());
    GuiLabel({ accPos.x, accPos.y, cardWidth - 2 * padding, 30 }, accuracyStr.c_str());
    GuiLabel({ wpmPos.x, wpmPos.y, cardWidth - 2 * padding, 30 }, wpmStr.c_str());

    // Restore previous styles
    GuiSetStyle(DEFAULT, TEXT_SIZE, prevTextSize);
    GuiSetStyle(DEFAULT, TEXT_SPACING, prevTextSpacing);
    GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, prevLabelColor);
    GuiSetStyle(LABEL, BASE_COLOR_NORMAL, prevLabelBg);
}

void Game::ShowWords(string str, int yOffset)
{

    float fontSize = 60.0f;
    GuiSetStyle(DEFAULT, TEXT_SIZE, ( int )fontSize);
    GuiSetStyle(DEFAULT, TEXT_SPACING, 4);
    GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(LABEL, BASE_COLOR_NORMAL, ColorToInt(BLACK));
    Vector2 size = MeasureTextEx(GetFontDefault(), str.c_str(), fontSize, 4.0f);
    Rectangle rect = {
        GetScreenWidth() / 2.0f - size.x / 2.0f - 10,
        GetScreenHeight() / 2.0f - size.y / 2.0f - yOffset,
        size.x + 20,
        size.y + 20
    };
    GuiLabel(rect, str.c_str());
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, TEXT_SPACING, 2);
    GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, ColorToInt(GRAY));
    GuiSetStyle(LABEL, BASE_COLOR_NORMAL, ColorToInt(BLANK));

}

void Game::ShowPowerUps()
{
    float x = GetScreenWidth() - powerUpTexture.width - 5;
    float y = GetScreenHeight() - powerUpTexture.height;
    if ( powerUps > 0 )
    {
        float t = GetTime();
        float scale = 1.0f + 0.1f * sin(t * 6);
        float iconWidth = powerUpTexture.width;
        float iconHeight = powerUpTexture.height;

        float centerX = x + iconWidth / 2;
        float centerY = y + iconHeight / 2;
        Rectangle dest =
        {
            centerX,
            centerY,
            iconWidth * scale,
            iconHeight * scale
        };
        Vector2 origin = { iconWidth * scale / 2,iconHeight * scale / 2 };
        DrawTexturePro(
            powerUpTexture,
            { 0,0,iconWidth,iconHeight },
            dest,
            origin,
            0.0f,
            WHITE
        );

    }
    else
    {
        DrawTextureV(powerUpTexture, { x,y }, WHITE);
    }
    x -= 10;
    DrawText(to_string(powerUps).c_str(), x, y, 30, WHITE);

}

void Game::ShowProgressbar()
{
    if ( !canPowerUp )
    {
        return;
    }
    float progress = ( float )numWordsWithoutMiss;
    float progressGoal = ( float )level + ( level / 2 ) + 4;
    float barWidth = 300;
    float barHeight = 20;
    float barX = GetScreenWidth() / 2.0f - barWidth / 2.0f;
    float barY = GetScreenHeight() - 50;
    Rectangle progressBarRect = { barX,barY,barWidth,barHeight };

    GuiProgressBar(progressBarRect, "Power Up", NULL, &progress, 0.0f, progressGoal);

}

void Game::ActivatePowerup()
{
    Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
    vector<pair<float, WordShip*>>targets;
    for ( auto& wordship : wordships )
    {
        if ( wordship.alive )
        {
            float distance = Vector2Distance(wordship.GetCenter(), shipCenter);
            targets.push_back({ distance,&wordship });
        }
    }
    sort(targets.begin(), targets.end());

    for ( int i = 0; i < min(level, ( int )targets.size()); i++ )
    {
        WordShip* targetShip = targets[i].second;
        playership.powerUpBullets.push_back(Bullet(shipCenter, targetShip, 50.0f, true));
    }
}


int Game::GetTargetWordIdx(char typed)
{
    Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
    vector<pair<float, int>>targets;
    for ( int i = 0; i < wordships.size(); i++ )
    {
        float distance = Vector2Distance(shipCenter, wordships[i].GetCenter());
        targets.push_back({ distance,i });
    }
    sort(targets.begin(), targets.end());

    for ( int i = 0; i < ( int )targets.size(); i++ )
    {
        if ( wordships[targets[i].second].word.empty() || !wordships[targets[i].second].alive )continue;
        Rectangle rect = wordships[targets[i].second].GetRect();
        if ( rect.y < 0 ) continue;
        if ( wordships[targets[i].second].word[wordships[targets[i].second].typedCount] == typed )
        {
            return targets[i].second;
        }
    }
    return -1;
}


int Game::LoadHighScore()
{
    int prevHighScore = 0;
    ifstream highScoreFile("highscore.txt");

    if ( highScoreFile.is_open() )
    {
        if ( !( highScoreFile >> prevHighScore ) )
        {
            cerr << "Invalid highscore format. Resetting to 0.\n";
            prevHighScore = 0;
        }
        highScoreFile.close();
    }
    else
    {
        cerr << "Failed to load highscore from file\n";
    }

    return prevHighScore;
}

void Game::SaveHighScore(int curScore)
{
    ofstream highscoreFile("highscore.txt", ios::out | ios::trunc);
    if ( highscoreFile.is_open() )
    {
        highscoreFile << curScore;
        highscoreFile.close();
    }
    else
    {
        cerr << "Failed to save highscore to file\n";
    }
}

void Game::DeleteInactiveBullets()
{

    auto it = playership.bullets.begin();
    while ( it != playership.bullets.end() )
    {
        if ( !it->active || it->target == nullptr || !it->target->alive )
        {
            it = playership.bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }


}
void Game::DeleteInactivePowerdUpBullets()
{
    auto it = playership.powerUpBullets.begin();
    while ( it != playership.powerUpBullets.end() )
    {
        if ( !it->active || it->target == nullptr || !it->target->alive )
        {
            if ( isValid(target_idx) && it->target->word == wordships[target_idx].word )
            {
                target_idx = -1;
            }
            it = playership.powerUpBullets.erase(it);
        }
        else
        {
            ++it;
        }
    }


}

void Game::DeleteInactiveWordShips()
{

    auto it = wordships.begin();
    while ( it != wordships.end() )
    {
        if ( !it->alive )
        {
            if ( isValid(target_idx) && wordships[target_idx].word == it->word )
            {
                target_idx = -1;
            }
            it = wordships.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::DeleteFinishedExplosions()
{

    auto it = explosions.begin();
    while ( it != explosions.end() )
    {
        if ( it->isFinished() )
        {
            it = explosions.erase(it);
        }
        else
        {
            ++it;
        }
    }


}

void Game::DeleteInactiveImpacts()
{
    auto it = impacts.begin();
    while ( it != impacts.end() )
    {
        if ( it->isFinished() )
        {
            it = impacts.erase(it);
        }
        else
        {
            ++it;
        }
    }


}

void Game::HandleInput()
{
    if ( playership.alive ) playership.Move();
}


std::vector<WordShip> Game::CreateWordships()
{
    vector<WordShip>ships;
    vector<string>wordPool;
    int numberOfShips = level * 5;
    int ship_added = 0;
    int word_level = 1;
    while ( ship_added < numberOfShips )
    {
        int num_current_level_words = min(word_level * 2, numberOfShips - ship_added);
        int start_idx = GetRandomValue(0, max(0, ( ( int )levelWord[word_level].size() ) - num_current_level_words - 1));
        for ( int i = start_idx; i < ( start_idx + num_current_level_words ); i++ )
        {
            wordPool.push_back(levelWord[word_level][i]);
        }
        ship_added += num_current_level_words;
        if ( word_level < 10 )word_level++;

    }
    std::shuffle(wordPool.begin(), wordPool.end(), std::default_random_engine(GetTime() * 1000));

    float posx = 0;
    float posy = -30;
    float word_height = 40;
    float spacing = 10;
    for ( int i = 0; i < numberOfShips; i++ )
    {
        float word_width = MeasureTextEx(font, wordPool[i].c_str(), 50, 2).x + 20;
        if ( posx + word_width < GetScreenWidth() )
        {
            ships.push_back(WordShip(font, { posx,posy }, wordPool[i], level, false, false, playership.position));
        }
        else
        {
            posx = 0;
            posy -= word_height;
            ships.push_back(WordShip(font, { posx,posy }, wordPool[i], level, false, false, playership.position));
        }
        posx += word_width;
        posx += spacing;
    }


    return ships;
}

void Game::CreateMiniWordShips(Vector2 position, int level)
{
    int num_words = max(5, level);
    int idx = GetRandomValue(0, 25 - num_words);
    for ( int i = 0; i < num_words; i++ )
    {
        wordships.push_back(WordShip(font, position, oneLetterWords[( i + idx ) % 26], level, false, true, playership.position));
    }
}


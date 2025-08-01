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
    this->shouldClose = false;
    this->isPaused = false;
    this-> menuSelection = 0;
    this->selectedSettingIdx = 0;
    this-> totalMenuItems = 3;
    this->gameOverMenuItems = 2;
    this->musicVolume = 0.1f;
    this->soundVolume = 0.1f;
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
    assestsLoaded = false;
    score = 0;
    liveWords = 0;
    wordTyped = 0;
    timeSpentTyping = 0;
    typingStartTime = -1;
    lastWordShipDeathTime = -1;
    lastTypedTime = -1;
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
    music = LoadMusicStream("Sounds/background_music.ogg");

    wordTexture = LoadTexture("assets/e_f1.png");
    rocketTexture = LoadTexture("assets/rocket_1.png");
    bulletTexture = LoadTexture("assets/bullet.png");
    powerUpTexture = LoadTexture("assets/powered_bullet.png");
    explosionTexture = LoadTexture("assets/explosion.png");
    impactTexture = LoadTexture("assets/explosion-sheet.png");


    explosionSound = LoadSound("Sounds/explosion.ogg");
    impactSound = LoadSound("Sounds/NenadSimic - Muffled Distant Explosion.wav");
    errorSound = LoadSound("Sounds/game_error_sound.wav");
    levelCompleteSound = LoadSound("Sounds/newthingget.ogg");
    powerUpSound = LoadSound("Sounds/Win_sound.wav");
    playerDeathSound = LoadSound("Sounds/player_death.mp3");
    powerUpFireSound = LoadSound("Sounds/burst_fire.mp3");
    gameOverSound = LoadSound("Sounds/GAMEOVER.wav");
    nevigationSound = LoadSound("Sounds/ui_nav.wav");
    selectSound = LoadSound("Sounds/ui_select.wav");
    UpdateAllSoundVolumes();

}

void Game::InitGame()
{
    Initialize();
    if ( !assestsLoaded )
    {
        LoadAssets();
        assestsLoaded = true;
    }
    PlayMusicStream(music);
    SetMusicVolume(music, musicVolume);
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
    for ( auto& explosion : explosions )
    {
        explosion.Draw();
    }
    for ( auto& impact : impacts )
    {
        impact.Draw();
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
        Rectangle settingsBtn = { ( float )x,( float )y + 70.0f,( float )buttonWidth,( float )buttonHeight };
        Rectangle quitBtn = { ( float )x,( float )y + 140.0f,( float )buttonWidth,( float )buttonHeight };


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

        // reset style
        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));


        if ( menuSelection == 1 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }
        bool settingPressed = GuiButton(settingsBtn, "Settings") || ( menuSelection == 1 && IsKeyPressed(KEY_ENTER) );

        // reset style
        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( menuSelection == 2 )
        {
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(hoverBorder));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(hoverBase));
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(hoverText));
        }
        bool quitPressed = GuiButton(quitBtn, "Quit") || ( menuSelection == 2 && IsKeyPressed(KEY_ENTER) );


        GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(defaultBorder));
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(defaultBase));
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(defaultText));

        if ( startPressed )
        {
            PlaySound(selectSound);
            InitGame();
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        if ( settingPressed )
        {
            PlaySound(selectSound);
            gameState = SETTINGS;
        }
        if ( quitPressed ) {
            PlaySound(selectSound);
            shouldClose = true;
        }
        return;
    }
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
            PlaySound(selectSound);
            playership.alive = true;
            InitGame();
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        if ( quitPressed ) {
            PlaySound(selectSound);
            shouldClose = true;
        }
        return;

    }
    if ( gameState == SHOW_NEXT_LEVEL )
    {
        string str = "LEVEL " + to_string(level);
        ShowWords(str, 0);
        return;
    }

    if ( gameState == SETTINGS )
    {
        const int x = GetScreenWidth() / 2 - 150;
        const int y = 150;
        ShowSettings(x, y);
        DrawText(TextFormat("%d%%", ( int )( soundVolume * 100 )), x + 240, y + 50, 20, WHITE);
        string text = "Press Space to go back";
        DrawText(text.c_str(), x, y + 300, 20, WHITE);
        if ( IsKeyPressed(KEY_SPACE) ) {
            PlaySound(selectSound);
            gameState = MAIN_MENU;
        }
        return;
    }
    if ( gameState == PLAYING || gameState == PAUSED )
    {
        if ( playership.alive && lives > 0 )
        {
            playership.Draw(playership.image_idx);

            playership.image_idx++;
            playership.image_idx %= ( ( int )playership.images.size() );
            float x = 0 + playership.image.width / 2;
            float y = GetScreenHeight() - playership.image.height;
            for ( int i = 0; i + 1 < lives; i++ )
            {
                Vector2 pos = { x,y };
                DrawTextureV(playership.image, pos, WHITE);
                x += playership.image.width + 10;
            }
        }

        if ( gameState == PAUSED )
        {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));
            const int x = GetScreenWidth() / 2 - 150;
            const int y = 150;
            ShowSettings(x, y);
            DrawText(TextFormat("%d%%", ( int )( soundVolume * 100 )), x + 240, y + 50, 20, WHITE);
            string text = "Press Space to Continue.";
            DrawText(text.c_str(), x, y + 300, 20, WHITE);
        }
        ShowPowerUps();
        ShowProgressbar();

        return;
    }

    if ( gameState == LEVEL_COMPLETED )
    {
        // show score and accuracy
        ShowResult(0);
        string str = "LEVEL COMPLETE";
        ShowWords(str, 150);
        return;
    }


}

void Game::Update()
{
    UpdateMusicStream(music);
    if ( gameState == PAUSED || gameState == GAME_OVER )
    {
        return;
    }
    if ( !isValid(target_idx) )
    {
        target_idx = -1;
    }
    for ( auto& impact : impacts )
    {
        impact.Update();
    }
    for ( auto& explosion : explosions )
    {
        explosion.Update();
    }
    for ( auto& bullet : playership.bullets )
    {
        bullet.Update();
    }
    for ( auto& bullet : playership.powerUpBullets )
    {
        bullet.Update();
    }
    for ( auto& word : wordships )
    {
        word.Move();
    }

    CheckCollisions();
    DeleteInactiveBullets();
    DeleteInactivePowerdUpBullets();
    DeleteFinishedExplosions();
    DeleteInactiveImpacts();

    if ( gameState == SHOW_NEXT_LEVEL )
    {
        if ( GetTime() - levelStartTime > 1.5f )
        {
            if ( score > highScore )
            {
                SaveHighScore(score);
                highScore = LoadHighScore();
            }
            if ( !isValid(target_idx) )target_idx = -1;
            wordships = CreateWordships();
            liveWords = wordships.size();
            gameState = PLAYING;
        }
        return;
    }
    if ( gameState == PLAYING && typingStartTime != -1 )
    {
        if ( lastTypedTime != -1 && GetTime() - lastTypedTime > 5.0f )
        {
            timeSpentTyping += ( GetTime() - typingStartTime );
            typingStartTime = -1;
            lastTypedTime = -1;
        }
    }
    if ( gameState == PLAYING && GetLiveWordCount() == 0 )
    {
        if ( bossIsDead )
        {
            if ( GetTime() - lastWordShipDeathTime >= 0.5f )
            {
                PlaySound(levelCompleteSound);
                score += numWordsWithoutMiss;
                if ( numWordsWithoutMiss >= level * 5 )
                {
                    score += ( level * 10 );
                }
                if ( score > highScore )
                {
                    SaveHighScore(score);
                    highScore = LoadHighScore();
                }
                lastWordShipDeathTime = -1;
                wordships.clear();
                bossIsDead = false;
                bossCreated = false;
                timeSpentTyping += ( GetTime() - typingStartTime );

                if ( !isValid(target_idx) )target_idx = -1;
                levelStartTime = GetTime();
                typingStartTime = -1;
                gameState = lives > 0 ? LEVEL_COMPLETED : GAME_OVER;
            }

        }
        else
        {
            // create boss word
            if ( !bossCreated )
            {
                bossCreated = true;
                int boss_level = min(10, level);
                int boss_idx = GetRandomValue(0, ( int )bossLevelWord[boss_level].size() - 1);
                std::string boss_word = bossLevelWord[boss_level][boss_idx];
                int offset = GetRandomValue(0, GetScreenWidth() / 2 - 200);
                int sign = GetRandomValue(0, 1) == 0 ? -1 : 1;
                offset *= sign;
                int posX = ( GetScreenWidth() / 2 ) + offset;
                int posY = - 10;
                Vector2 pos = { posX,posY };
                wordships.push_back(WordShip(font, pos, wordTexture, boss_word, level, true, false, playership.position));
            }
        }

        return;
    }
    if ( gameState == PLAYING && !playership.alive )
    {
        if ( lives > 0 )
        {
            for ( auto& wordship : wordships )
            {
                if ( wordship.isMinionShip )
                {
                    wordship.alive = false;
                }
            }
            if ( GetTime() - lastDeathTime > 1.5f )
            {
                playership.alive = true;
                playership.position.x = GetScreenWidth() / 2;
                playership.position.y = GetScreenHeight() - 100;
            }
        }
        else
        {
            if ( score > highScore )
            {
                SaveHighScore(score);
                highScore = LoadHighScore();
            }

            for ( auto& wordship : wordships )
            {
                wordship.alive = false;
            }
            PlaySound(gameOverSound);
            gameState = GAME_OVER;
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
            if ( !isValid(target_idx) )target_idx = -1;
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        return;
    }

    return;


}

void Game::CheckCollisions()
{
    CheckCollisionsBulletVsWordships();
    CheckCollisionsPowerBulletVsWordships();
    CheckCollisionsWordshipsVsWordships();
    CheckCollisionsWordshipVsPlayership();
}

void Game::CheckCollisionsBulletVsWordships()
{
    for ( auto& bullet : playership.bullets )
    {
        if ( bullet.active && bullet.target && bullet.target->alive )
        {
            if ( CheckCollisionRecs(bullet.GetRect(), bullet.target->GetImageRect()) || CheckCollisionRecs(bullet.GetRect(), bullet.target->GetRect()) )
            {
                bullet.active = false;
                if ( bullet.target->isMinionShip || bullet.target->isReadytoDestroy )
                {
                    PlaySound(explosionSound);
                    Vector2 explosionPos = bullet.target->GetCenter();
                    explosions.emplace_back(&explosionTexture, explosionPos);
                    bullet.target->alive = false;
                    return;
                }
                else
                {
                    Vector2 hitPos = bullet.target->GetCenter();
                    PlaySound(impactSound);
                    impacts.emplace_back(&impactTexture, hitPos);
                }
            }
        }

    }

}

void Game::CheckCollisionsPowerBulletVsWordships()
{
    for ( auto& bullet : playership.powerUpBullets )
    {
        if ( bullet.active && bullet.target && bullet.target->alive )
        {
            if ( CheckCollisionRecs(bullet.GetRect(), bullet.target ->GetImageRect()) || CheckCollisionRecs(bullet.GetRect(), bullet.target->GetRect()) )
            {
                // power bullets will destroy the ship on contact no matter that state of the ship
                Vector2 explosionPos = bullet.target->GetCenter();
                explosions.emplace_back(&explosionTexture, explosionPos);
                PlaySound(explosionSound);
                if ( bullet.target->isBoss )
                {
                    bossIsDead = true;
                    CreateMiniWordShips(bullet.target->position, level);
                }
                bullet.active = false;
                bullet.target->alive = false;
            }
        }
    }
}

void Game::CheckCollisionsWordshipsVsWordships()
{

    for ( int i = 0; i < ( int )wordships.size(); i++ )
    {
        if ( !wordships[i].alive )continue;
        for ( int j = i + 1; j < ( int )wordships.size(); j++ )
        {
            if ( !wordships[j].alive )continue;
            bool collision = CheckCollisionRecs(wordships[i].GetRect(), wordships[j].GetRect()) ||
                CheckCollisionRecs(wordships[i].GetRect(), wordships[j].GetImageRect()) ||
                CheckCollisionRecs(wordships[i].GetImageRect(), wordships[j].GetRect());
            if ( collision )
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
}

void Game::CheckCollisionsWordshipVsPlayership()
{
    if ( gameState != PLAYING ) return;
    for ( auto& wordship : wordships )
    {
        if ( CheckCollisionRecs(wordship.GetImageRect(), playership.GetRect()) || CheckCollisionRecs(wordship.GetRect(), playership.GetRect()) )
        {
            std::cout << "COLLISION!!!!\n";
            // trigger explosion
            PlaySound(playerDeathSound);
            Vector2 explosionPos = { playership.position.x + playership.image.width / 2,playership.position.y };
            explosions.emplace_back(&explosionTexture, explosionPos);
            if ( wordship.isBoss )
            {
                bossIsDead = true;
            }
            lastDeathTime = GetTime();
            wordship.alive = false;
            playership.alive = false;
            lives--;
            return;
        }
    }
}

bool Game::isValid(int idx)
{
    if ( idx < 0 || idx >= ( int )wordships.size() || ( !wordships[idx].alive ) || ( wordships[idx].isReadytoDestroy ) )return false;
    if ( isWordOutofScreen(idx) )return false;
    if ( wordships[idx].position.y < 0 )return false;
    return true;
}


bool Game::isWordOutofScreen(int idx)
{
    if ( idx < 0 || idx >= ( int )wordships.size() )return true;
    if ( wordships[idx].position.x < 0 || wordships[idx].position.x > GetScreenWidth() )return true;
    if ( wordships[idx].position.y > GetScreenHeight() )return true;
    return false;
}

void Game::HandleTyping()
{
    char typed = playership.Fire();
    if ( typed == '\0' )return;
    if ( !isValid(target_idx) )
    {
        target_idx = GetTargetWordIdx(typed);
    }
    if ( isValid(target_idx) )
    {
        totalKeyStrokes++;
        if ( typingStartTime == -1 )
        {
            typingStartTime = GetTime();
            if ( lastTypedTime == -1 )
            {
                lastTypedTime = typingStartTime;
            }
        }
        if ( wordships[target_idx].word[wordships[target_idx].typedCount] == typed )
        {
            score++;
            successfulKeyStrokes++;
            wordships[target_idx].typedCount++;
            // if word is completed 
            if ( wordships[target_idx].typedCount >= ( int )wordships[target_idx].word.size() )
            {
                wordships[target_idx].isReadytoDestroy = true;
                wordships[target_idx].wordDestroyedTime = GetTime();
                wordTyped ++;

                PlaySound(playership.LaserSound);
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
                playership.bullets.push_back(Bullet(bulletTexture, shipCenter, &wordships[target_idx], 40.0f, false));


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


                if ( wordships[target_idx].isBoss )
                {
                    bossIsDead = true;
                    // create mini wordships
                    Vector2 position = wordships[target_idx].shipPosition;
                    CreateMiniWordShips(position, level);
                }
                target_idx = -1;
                return;
            }
            else
            {
                PlaySound(playership.LaserSound);
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
                playership.bullets.push_back(Bullet(bulletTexture, shipCenter, &wordships[target_idx], 40.0f, false));
            }

        }
        else
        {
            PlaySound(errorSound);
            hasMissTyped = true;
            numWordsWithoutMiss = 0;
            if ( wordships[target_idx].isBoss )
            {
                Vector2 position = wordships[target_idx].shipPosition;
                CreateMiniWordShips(position, level);
                wordships[target_idx].typedCount = 0;
                target_idx = -1;
            }

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
    if ( timeSpentTyping != 0 )
    {
        wpm = std::max(0, ( wordTyped * 60 ) / timeSpentTyping);
    }
    else
    {
        wpm = 0;
    }

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
void Game::ShowSettings(int x, int y)
{
    DrawText("Settings", GetScreenWidth() / 2 - MeasureText("Settings", 40) / 2, 80, 40, WHITE);

    if ( selectedSettingIdx == 0 )
        DrawRectangle(x - 10, y - 5, 300, 30, Fade(SKYBLUE, 0.4f));

    DrawText("Music Volume", x, y, 20, RAYWHITE);
    if ( GuiButton({ x + 160.0f,( float )y - 5, 30, 30 }, "-") && musicVolume > 0.0f )
    {
        PlaySound(selectSound);
        musicVolume = std::max(0.0f, musicVolume - 0.1f);
        SetMusicVolume(music, musicVolume);
    }
    if ( GuiButton({ x + 200.0f, ( float )y - 5, 30, 30 }, "+") && musicVolume < 1.0f )
    {
        PlaySound(selectSound);
        musicVolume = std::min(1.0f, musicVolume + 0.1f);
        SetMusicVolume(music, musicVolume);
    }
    DrawText(TextFormat("%d%%", ( int )( musicVolume * 100 )), x + 240, y, 20, WHITE);

    if ( selectedSettingIdx == 1 )
        DrawRectangle(x - 10, y + 45, 300, 30, Fade(SKYBLUE, 0.4f));

    DrawText("SFX Volume", x, y + 50, 20, RAYWHITE);
    if ( GuiButton({ x + 160.0f, y + 45.0f, 30, 30 }, "-") && soundVolume > 0.0f )
    {
        PlaySound(selectSound);
        soundVolume = std::max(0.0f, soundVolume - 0.1f);
        UpdateAllSoundVolumes();
    }
    if ( GuiButton({ x + 200.0f, y + 45.0f, 30, 30 }, "+") && soundVolume < 1.0f )
    {
        PlaySound(selectSound);
        soundVolume = std::min(1.0f, soundVolume + 0.1f);
        UpdateAllSoundVolumes();
    }
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
void Game::ShowWords(string str, Rectangle rect)
{
    float fontSize = 30.0f;
    GuiSetStyle(DEFAULT, TEXT_SIZE, ( int )fontSize);
    GuiSetStyle(DEFAULT, TEXT_SPACING, 4);
    GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(LABEL, BASE_COLOR_NORMAL, ColorToInt(BLACK));
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
        string str = "Press Enter";
        int width = MeasureText(str.c_str(), 20);
        DrawText(str.c_str(), x - width / 2, y - 20, 20, WHITE);

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
    float barY = GetScreenHeight() - 30;
    Rectangle progressBarRect = { barX,barY,barWidth,barHeight };

    GuiProgressBar(progressBarRect, "Streak", NULL, &progress, 0.0f, progressGoal);

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
        playership.powerUpBullets.push_back(Bullet(rocketTexture, shipCenter, targetShip, 50.0f, true));
    }
}


int Game::GetTargetWordIdx(char typed)
{
    Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
    vector<pair<float, int>>targets;
    for ( int i = 0; i < wordships.size(); i++ )
    {
        if ( !isValid(i) )continue;
        float distance = Vector2Distance(shipCenter, wordships[i].GetCenter());
        targets.push_back({ distance,i });
    }
    sort(targets.begin(), targets.end());

    for ( int i = 0; i < ( int )targets.size(); i++ )
    {
        if ( !isValid(targets[i].second) )continue;
        Rectangle rect = wordships[targets[i].second].GetRect();
        if ( rect.y < 0 ) continue;
        if ( wordships[targets[i].second].word[wordships[targets[i].second].typedCount] == typed )
        {
            return targets[i].second;
        }
    }
    return -1;
}

int Game::GetLiveWordCount()
{
    int cnt = 0;
    for ( int i = 0; i < wordships.size(); i++ )
    {
        if ( !wordships[i].alive || wordships[i].isReadytoDestroy || isWordOutofScreen(i) )
        {
            continue;
        }
        else
        {
            cnt++;
        }
    }
    if ( cnt == 0 && bossIsDead && lastWordShipDeathTime == -1 )
    {
        lastWordShipDeathTime = GetTime();
    }
    return cnt;
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
            if ( isValid(target_idx) && it->target == &wordships[target_idx] )
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
        if ( !it->alive || ( it->isReadytoDestroy && ( GetTime() - it->wordDestroyedTime > 0.5f ) ) )
        {
            it = wordships.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::UpdateAllSoundVolumes()
{
    SetSoundVolume(playership.LaserSound, soundVolume);
    SetSoundVolume(explosionSound, soundVolume);
    SetSoundVolume(impactSound, soundVolume);
    SetSoundVolume(errorSound, soundVolume);
    SetSoundVolume(powerUpSound, soundVolume);
    SetSoundVolume(levelCompleteSound, soundVolume);
    SetSoundVolume(gameOverSound, soundVolume);
    SetSoundVolume(playerDeathSound, soundVolume);
    SetSoundVolume(powerUpFireSound, soundVolume);
    SetSoundVolume(nevigationSound, soundVolume);
    SetSoundVolume(selectSound, soundVolume);
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
    if ( gameState == PAUSED || gameState == SETTINGS )
    {
        if ( IsKeyPressed(KEY_DOWN) ) {
            selectedSettingIdx = ( selectedSettingIdx + 1 ) % 2;  // Only 2 options
            PlaySound(nevigationSound);
        }
        if ( IsKeyPressed(KEY_UP) ) {
            selectedSettingIdx = ( selectedSettingIdx - 1 + 2 ) % 2;
            PlaySound(nevigationSound);
        }
        if ( IsKeyPressed(KEY_LEFT) ) {
            if ( selectedSettingIdx == 0 && musicVolume > 0.0f ) {
                musicVolume = std::max(0.0f, musicVolume - 0.1f);
                SetMusicVolume(music, musicVolume);
                PlaySound(selectSound);
            }
            else if ( selectedSettingIdx == 1 && soundVolume > 0.0f ) {
                soundVolume = std::max(0.0f, soundVolume - 0.1f);
                UpdateAllSoundVolumes();
                PlaySound(selectSound);
            }
        }
        if ( IsKeyPressed(KEY_RIGHT) ) {
            if ( selectedSettingIdx == 0 && musicVolume < 1.0f ) {
                musicVolume = std::min(1.0f, musicVolume + 0.1f);
                SetMusicVolume(music, musicVolume);
                PlaySound(selectSound);
            }
            else if ( selectedSettingIdx == 1 && soundVolume < 1.0f ) {
                soundVolume = std::min(1.0f, soundVolume + 0.1f);
                UpdateAllSoundVolumes();
                PlaySound(selectSound);
            }
        }
    }
    if ( gameState == MAIN_MENU )
    {
        if ( IsKeyPressed(KEY_DOWN) )
        {
            PlaySound(nevigationSound);
            menuSelection = ( menuSelection + 1 ) % totalMenuItems;
        }
        if ( IsKeyPressed(KEY_UP) )
        {
            PlaySound(nevigationSound);
            menuSelection = ( ( menuSelection - 1 ) + totalMenuItems ) % totalMenuItems;
        }
    }
    if ( gameState == GAME_OVER )
    {
        if ( IsKeyPressed(KEY_DOWN) )
        {
            PlaySound(nevigationSound);
            menuSelection = ( menuSelection + 1 ) % gameOverMenuItems;
        }
        if ( IsKeyPressed(KEY_UP) )
        {
            PlaySound(nevigationSound);
            menuSelection = ( ( menuSelection - 1 ) + gameOverMenuItems ) % gameOverMenuItems;
        }
    }

    if ( IsKeyPressed(KEY_SPACE) )
    {
        PlaySound(selectSound);
        if ( gameState == PLAYING )
        {
            if ( typingStartTime != -1 )
            {
                timeSpentTyping += ( GetTime() - typingStartTime );
                typingStartTime = -1;
                lastTypedTime = -1;
            }
            gameState = PAUSED;
            isPaused = true;
        }
        else if ( gameState == PAUSED )
        {
            gameState = PLAYING;
            isPaused = false;
        }
    }
    if ( IsKeyPressed(KEY_ENTER) && gameState == PLAYING )
    {
        if ( powerUps > 0 )
        {
            PlaySound(powerUpFireSound);
            ActivatePowerup();
            powerUps--;
        }
    }
    if ( gameState == PLAYING )HandleTyping();
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

    float posx = GetRandomValue(100, GetScreenWidth() - 100);
    float posy = -30;
    float word_height = 60;
    float spacing = 20;
    for ( int i = 0; i < numberOfShips; i++ )
    {
        float word_width = MeasureTextEx(font, wordPool[i].c_str(), 50, 2).x + 20;
        if ( posx + word_width < GetScreenWidth() )
        {
            ships.push_back(WordShip(font, { posx,posy }, wordTexture, wordPool[i], level, false, false, playership.position));
        }
        else
        {
            posx = 0;
            posy -= word_height;
            ships.push_back(WordShip(font, { posx,posy }, wordTexture, wordPool[i], level, false, false, playership.position));
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
        wordships.push_back(WordShip(font, position, wordTexture, oneLetterWords[( i + idx ) % 26], level, false, true, playership.position));
    }
}


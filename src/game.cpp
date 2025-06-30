#include "game.hpp"
#include <string>
#include "bullet.hpp"
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
using namespace std;

vector<string>smallerwords =
{
    "go","come","back","not","far","away","chose","rise","wise","lazy","loser","win","lose",
    "eat","drink","party","live","life","earn","buy","sell","full","empty","full","laugh","right",
    "wrong","teach","write","read","sleep","reap","sow","left","antiestablishmentarianism"
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

Game::Game(Font f) :font(f)
{
    this->gameState = SHOW_NEXT_LEVEL;
    this->levelStartTime = 0;
    this->levelDelay = 3.0f;
    this->music = LoadMusicStream("Sounds/background_music.ogg");
    PlayMusicStream(music);
    SetMusicVolume(music, 0.5f);
    InitGame();
}

Game::~Game()
{
    UnloadFont(font);
    UnloadTexture(explosionTexture);
    UnloadTexture(impactTexture);
    UnloadMusicStream(music);
}

void Game::Draw()
{
    playership.Draw();
    for ( int i = 0; i < ( int )wordships.size(); i++ )
    {
        wordships[i].Draw(i == target_idx);
    }

    for ( auto& bullet : playership.bullets )
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
    if ( gameState == GAME_OVER )
    {
        string str = "GAME OVER";
        Vector2 size = MeasureTextEx(font, str.c_str(), 60, 4);
        DrawTextEx(font, str.c_str(), { GetScreenWidth() / 2 - size.x / 2,GetScreenHeight() / 2 - size.y / 2 }, 60, 4, YELLOW);
    }
    if ( gameState == LEVEL_COMPLETED || gameState == SHOW_NEXT_LEVEL )
    {
        string levelMsg = "LEVEL " + to_string(level);
        Vector2 size = MeasureTextEx(font, levelMsg.c_str(), 60, 4);
        DrawTextEx(font, levelMsg.c_str(), { GetScreenWidth() / 2 - size.x / 2,GetScreenHeight() / 2 - size.y / 2 }, 60, 4, YELLOW);
    }
}

void Game::Update()
{
    UpdateMusicStream(music);
    for ( auto& bullet : playership.bullets )
    {
        bullet.Update();
    }
    for ( auto& explosion : explosions )
    {
        explosion.Update();
    }
    for ( auto& impact : impacts )
    {
        impact.Update();
    }
    if ( gameState == GAME_OVER )
    {
        cout << "GAME OVER\n";
        return;
    }
    if ( gameState == PLAYING && wordships.empty() )
    {
        cout << "Level Completed\n";
        gameState = LEVEL_COMPLETED;
        levelStartTime = GetTime();
        return;
    }
    if ( gameState == LEVEL_COMPLETED )
    {
        if ( GetTime() - levelStartTime > levelDelay )
        {
            gameState = SHOW_NEXT_LEVEL;
            levelStartTime = GetTime();
        }
        return;
    }
    if ( gameState == SHOW_NEXT_LEVEL )
    {
        if ( GetTime() - levelStartTime > 1.5f )
        {
            level++;
            target_idx = -1;
            wordships = CreateWordships();
            gameState = PLAYING;
        }
        return;
    }
    for ( auto& word : wordships )
    {
        word.Move();
    }

    HandleTyping();
    DeleteInactiveBullets();
    DeleteInactiveWordShips();
    DeleteFinishedExplosions();
    CheckCollisions();
}

void Game::CheckCollisions()
{
    if ( target_idx != -1 )
    {
        // bullets vs wordships
        for ( auto& bullet : playership.bullets )
        {
            if ( CheckCollisionRecs(bullet.GetRect(), wordships[target_idx].GetRect()) )
            {
                bullet.active = false;
                Vector2 hitPos = bullet.position;
                impacts.emplace_back(&impactTexture, hitPos);
                PlaySound(impactSound);
            }
        }

    }

    // wordship vs playership
    for ( auto& wordship : wordships )
    {
        if ( CheckCollisionRecs(wordship.GetRect(), playership.GetRect()) )
        {

            playership.alive = false;
            wordship.alive = false;
            lives--;
            // trigger explosion
            Vector2 explosionPos = { playership.position.x + playership.image.width / 2,playership.position.y };
            explosions.emplace_back(&explosionTexture, explosionPos);
            PlaySound(explosionSound);
            if ( lives == 0 )
            {
                isRunning = false;
                gameState = GAME_OVER;
            }
            else
            {
                playership.alive = true;
            }
        }
    }
    // wordship vs wordship
    for ( int i = 0; i < wordships.size(); i++ )
    {
        for ( int j = i + 1; j < wordships.size(); j++ )
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
                        wordships[i].position.y -= overlapY / 2;
                        wordships[j].position.y += overlapY / 2;
                    }

                    swap(wordships[i].velocity.x, wordships[j].velocity.x);
                    swap(wordships[i].velocity.y, wordships[j].velocity.y);
                }
            }
        }
    }

}

void Game::HandleTyping()
{
    char typed = playership.Fire();
    if ( typed == '\0' )return;
    if ( wordships.empty() )
    {
        std::cout << "Level Completed\n";
        gameState = LEVEL_COMPLETED;
        levelStartTime = GetTime();
        return;
    }
    if ( target_idx == -1 && !wordships[target_idx].alive )
    {
        target_idx = -1;
    }
    if ( target_idx == -1 )
    {
        target_idx = GetTargetWordIdx(typed);
        if ( target_idx != -1 )
        {
            if ( wordships[target_idx].word[wordships[target_idx].typedCount] == typed )
            {
                PlaySound(playership.LaserSound);
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
                playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 20.0f));

                wordships[target_idx].typedCount++;

                if ( wordships[target_idx].typedCount >= ( int )wordships[target_idx].word.size() )
                {
                    // trigger explosion
                    Vector2 explosionPos = wordships[target_idx].GetCenter();
                    explosions.emplace_back(&explosionTexture, explosionPos);
                    PlaySound(explosionSound);
                    wordships[target_idx].alive = false;
                    target_idx = -1;
                }
            }
            else
            {
                PlaySound(errorSound);
            }
        }
    }
    else
    {
        if ( wordships[target_idx].word[wordships[target_idx].typedCount] == typed )
        {
            PlaySound(playership.LaserSound);
            wordships[target_idx].typedCount++;

            // matched. So fire a bullet towards the wordship

            Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
            playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 20.0f));

            if ( wordships[target_idx].typedCount >= ( int )wordships[target_idx].word.size() )
            {
                Vector2 explosionPos = wordships[target_idx].GetCenter();
                explosions.emplace_back(&explosionTexture, explosionPos);
                PlaySound(explosionSound);
                wordships[target_idx].alive = false;
                target_idx = -1;
            }
        }
        else
        {
            PlaySound(errorSound);
        }
    }
}

int Game::GetTargetWordIdx(char typed)
{
    for ( int i = ( int )wordships.size() - 1; i >= 0; i-- )
    {
        if ( wordships[i].word.empty() || !wordships[i].alive )continue;
        Rectangle rect = wordships[i].GetRect();
        if ( rect.y < 0 ) continue;
        if ( wordships[i].word[0] == typed )
        {
            return i;
        }
    }
    return -1;
}


void Game::DeleteInactiveBullets()
{

    auto it = playership.bullets.begin();
    while ( it != playership.bullets.end() )
    {
        if ( !it->active )
        {
            it = playership.bullets.erase(it);
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
        bool targeted = false;
        for ( auto& bullet : playership.bullets )
        {
            if ( bullet.active && bullet.target == &( *it ) )
            {
                targeted = true;
                break;
            }
        }

        if ( !it->alive && !targeted )
        {
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

void Game::HandleInput()
{
    playership.Move();
}

void Game::InitGame()
{
    score = 0;
    highScore = 0;
    isRunning = true;
    lives = 3;
    level = 1;
    target_idx = -1;
    wordships = CreateWordships();
    explosionTexture = LoadTexture("assets/explosion.png");
    impactTexture = LoadTexture("assets/explosion-sheet.png");
    explosionSound = LoadSound("Sounds/explosion.ogg");
    impactSound = LoadSound("Sounds/NenadSimic - Muffled Distant Explosion.wav");
    errorSound = LoadSound("Sounds/caught.wav");
    for ( auto& [level, words] : levelWord )
    {
        shuffle(words.begin(), words.end(), default_random_engine(GetTime() * 1000));
    }
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
        word_level++;
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
            ships.push_back(WordShip(font, { posx,posy }, wordPool[i], level));
        }
        else
        {
            posx = 0;
            posy -= word_height;
            ships.push_back(WordShip(font, { posx,posy }, wordPool[i], level));
        }
        posx += word_width;
        posx += spacing;
    }
    return ships;
}


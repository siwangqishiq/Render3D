#ifndef _IINPUT_H_
#define _IINPUT_H_

/* The unknown key */
const int APP_KEY_INPUT_UNKNOWN  =      -1;

/* Printable keys */
const int APP_KEY_INPUT_SPACE           =   32;
const int APP_KEY_INPUT_APOSTROPHE      =   39;  
const int APP_KEY_INPUT_COMMA           =   44;  
const int APP_KEY_INPUT_MINUS           =   45;  
const int APP_KEY_INPUT_PERIOD          =   46;  
const int APP_KEY_INPUT_SLASH           =   47;  
const int APP_KEY_INPUT_0               =   48;
const int APP_KEY_INPUT_1               =   49;
const int APP_KEY_INPUT_2               =   50;
const int APP_KEY_INPUT_3               =   51;
const int APP_KEY_INPUT_4               =   52;
const int APP_KEY_INPUT_5               =   53;
const int APP_KEY_INPUT_6               =   54;
const int APP_KEY_INPUT_7               =   55;
const int APP_KEY_INPUT_8               =   56;
const int APP_KEY_INPUT_9               =   57;
const int APP_KEY_INPUT_SEMICOLON       =   59;  
const int APP_KEY_INPUT_EQUAL           =   61;  
const int APP_KEY_INPUT_A               =   65;
const int APP_KEY_INPUT_B               =   66;
const int APP_KEY_INPUT_C               =   67;
const int APP_KEY_INPUT_D               =   68;
const int APP_KEY_INPUT_E               =   69;
const int APP_KEY_INPUT_F               =   70;
const int APP_KEY_INPUT_G               =   71;
const int APP_KEY_INPUT_H               =   72;
const int APP_KEY_INPUT_I               =   73;
const int APP_KEY_INPUT_J               =   74;
const int APP_KEY_INPUT_K               =   75;
const int APP_KEY_INPUT_L               =   76;
const int APP_KEY_INPUT_M               =   77;
const int APP_KEY_INPUT_N               =   78;
const int APP_KEY_INPUT_O               =   79;
const int APP_KEY_INPUT_P               =   80;
const int APP_KEY_INPUT_Q               =   81;
const int APP_KEY_INPUT_R               =   82;
const int APP_KEY_INPUT_S               =   83;
const int APP_KEY_INPUT_T               =   84;
const int APP_KEY_INPUT_U               =   85;
const int APP_KEY_INPUT_V               =   86;
const int APP_KEY_INPUT_W               =   87;
const int APP_KEY_INPUT_X               =   88;
const int APP_KEY_INPUT_Y               =   89;
const int APP_KEY_INPUT_Z               =   90;
const int APP_KEY_INPUT_LEFT_BRACKET    =   91;  
const int APP_KEY_INPUT_BACKSLASH       =   92;  
const int APP_KEY_INPUT_RIGHT_BRACKET   =   93;  
const int APP_KEY_INPUT_GRAVE_ACCENT    =   96;  
const int APP_KEY_INPUT_WORLD_1         =   161; 
const int APP_KEY_INPUT_WORLD_2         =   162; 
const int APP_KEY_INPUT_ESCAPE          =   256;
const int APP_KEY_INPUT_ENTER           =   257;
const int APP_KEY_INPUT_TAB             =   258;
const int APP_KEY_INPUT_BACKSPACE       =   259;
const int APP_KEY_INPUT_INSERT          =   260;
const int APP_KEY_INPUT_DELETE          =   261;
const int APP_KEY_INPUT_RIGHT           =   262;
const int APP_KEY_INPUT_LEFT            =   263;
const int APP_KEY_INPUT_DOWN            =   264;
const int APP_KEY_INPUT_UP              =   265;
const int APP_KEY_INPUT_PAGE_UP         =   266;
const int APP_KEY_INPUT_PAGE_DOWN       =   267;
const int APP_KEY_INPUT_HOME            =   268;
const int APP_KEY_INPUT_END             =   269;
const int APP_KEY_INPUT_CAPS_LOCK       =   280;
const int APP_KEY_INPUT_SCROLL_LOCK     =   281;
const int APP_KEY_INPUT_NUM_LOCK        =   282;
const int APP_KEY_INPUT_PRINT_SCREEN    =   283;
const int APP_KEY_INPUT_PAUSE           =   284;
const int APP_KEY_INPUT_F1              =   290;
const int APP_KEY_INPUT_F2              =   291;
const int APP_KEY_INPUT_F3              =   292;
const int APP_KEY_INPUT_F4              =   293;
const int APP_KEY_INPUT_F5              =   294;
const int APP_KEY_INPUT_F6              =   295;
const int APP_KEY_INPUT_F7              =   296;
const int APP_KEY_INPUT_F8              =   297;
const int APP_KEY_INPUT_F9              =   298;
const int APP_KEY_INPUT_F10             =   299;
const int APP_KEY_INPUT_F11             =   300;
const int APP_KEY_INPUT_F12             =   301;
const int APP_KEY_INPUT_F13             =   302;
const int APP_KEY_INPUT_F14             =   303;
const int APP_KEY_INPUT_F15             =   304;
const int APP_KEY_INPUT_F16             =   305;
const int APP_KEY_INPUT_F17             =   306;
const int APP_KEY_INPUT_F18             =   307;
const int APP_KEY_INPUT_F19             =   308;
const int APP_KEY_INPUT_F20             =   309;
const int APP_KEY_INPUT_F21             =   310;
const int APP_KEY_INPUT_F22             =   311;
const int APP_KEY_INPUT_F23             =   312;
const int APP_KEY_INPUT_F24             =   313;
const int APP_KEY_INPUT_F25             =   314;
const int APP_KEY_INPUT_KP_0            =   320;
const int APP_KEY_INPUT_KP_1            =   321;
const int APP_KEY_INPUT_KP_2            =   322;
const int APP_KEY_INPUT_KP_3            =   323;
const int APP_KEY_INPUT_KP_4            =   324;
const int APP_KEY_INPUT_KP_5            =   325;
const int APP_KEY_INPUT_KP_6            =   326;
const int APP_KEY_INPUT_KP_7            =   327;
const int APP_KEY_INPUT_KP_8            =   328;
const int APP_KEY_INPUT_KP_9            =   329;
const int APP_KEY_INPUT_KP_DECIMAL      =   330;
const int APP_KEY_INPUT_KP_DIVIDE       =   331;
const int APP_KEY_INPUT_KP_MULTIPLY     =   332;
const int APP_KEY_INPUT_KP_SUBTRACT     =   333;
const int APP_KEY_INPUT_KP_ADD          =   334;
const int APP_KEY_INPUT_KP_ENTER        =   335;
const int APP_KEY_INPUT_KP_EQUAL        =   336;
const int APP_KEY_INPUT_LEFT_SHIFT      =   340;
const int APP_KEY_INPUT_LEFT_CONTROL    =   341;
const int APP_KEY_INPUT_LEFT_ALT        =   342;
const int APP_KEY_INPUT_LEFT_SUPER      =   343;
const int APP_KEY_INPUT_RIGHT_SHIFT     =   344;
const int APP_KEY_INPUT_RIGHT_CONTROL   =   345;
const int APP_KEY_INPUT_RIGHT_ALT       =   346;
const int APP_KEY_INPUT_RIGHT_SUPER     =   347;
const int APP_KEY_INPUT_INPUT_MENU      =   348;

const int APP_KEY_RELEASE    =            0; //按键释放
const int APP_KEY_PRESS      =            1; //按键按下
const int APP_KEY_REPEAT     =            2; //按键重复


//不同平台 输入事件处理
class IInput{
public:
    //获取按键状态  key按键是否被按下
    virtual int getKeyState(int key) = 0;
};

#endif 
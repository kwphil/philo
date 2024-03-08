use std::env;
use std::io::BufReader;
use std::fs::File;
use std::io::Read;

fn isalpha(c: char) -> bool {
    if c as u8 >= 65 && c as u8 <= 90 {
        return true;
    }
    
    if c as u8 >= 97 && c as u8 <= 122 {
        return true;
    }
        
    return false;
}

fn main() -> std::io::Result<()> {
    let argv:Vec<String> = env::args().collect();
    
    if argv.len() != 2 {
        panic!("Incorrect Usage");
    }
    
    let file = File::open(&argv[1])?;
    let mut contents = String::new();
    let mut bufReader = BufReader::new(file);
    let mut tokens: Vec<Token> = Vec::new();
    let mut i = 0;
    
    bufReader.read_to_string(&mut contents)?;
    let mut functions: Vec<Function> = Vec::new();
    
    tokenize(&contents, &mut tokens);
    
    /* Converting keywords here */
    for i in 0 .. tokens.len() - 1 {
        if tokens[i].TYPE == TokenType::UNKNOWN {
            if tokens[i].VALUE == "exit" {
                tokens[i].TYPE = TokenType::EXIT;
            }
            
            if tokens[i].VALUE == "fn" {
                tokens[i].TYPE = TokenType::FN;
            }
            
            if tokens[i].VALUE == "int" {
                tokens[i].TYPE = TokenType::INT;
            }
            
            if tokens[i].VALUE == "void" {
                tokens[i].TYPE = TokenType::VOID;
            }
            
            if tokens[i].VALUE == "char" {
                tokens[i].TYPE = TokenType::CHAR;
            }
        }
    }
    
    /* Creating parse tree */
    i = 0;
    while i < tokens.len() {
        if tokens[i].TYPE == TokenType::FN {
            let mut retFunc: Function = Function {
                NAME: "\0".to_string(),
                TYPE: ValueType::UNKNOWN,
                TYPE_SIZE: 0,
                PARAM: Vec::new(),
                PARAM_SIZE: Vec::new(),
                INSTRUCTS: Vec::new(),
                LOCATION: i as u64,
            };
        
            i+=1;
            
            if !(tokens[i].TYPE as i32 >= TokenType::INT as i32 && tokens[i].TYPE as i32 <= TokenType::NAME as i32) && !(tokens[i].TYPE == TokenType::UNKNOWN) {
                if tokens[i+1].TYPE == TokenType::COLON {
                    panic!("Unknown type for function: {}, being: {}", tokens[i+3].VALUE, tokens[i].VALUE);
                }
                panic!("Unknown type for function: {}, being: {}", tokens[i+1].VALUE, tokens[i].VALUE);
            }
            
            retFunc.TYPE = ValueType::from_i32(tokens[i].TYPE as i32 - TokenType::INT as i32);
            
            i+=1;
            
            let mut type_size: bool = false;
            
            /* Checking if function has defined size or not */
            if tokens[i].TYPE == TokenType::UNKNOWN  {
                type_size = true;
                if tokens[i].TYPE == TokenType::VOID {
                    retFunc.TYPE_SIZE = 0;
                } else {
                    retFunc.TYPE_SIZE = 4;
                }
            }
            
            if tokens[i].TYPE == TokenType::COLON {
                type_size = true;
                
                i += 1;
                
                if tokens[i].TYPE != TokenType::INT_LIT {
                    panic!("Expected INT_LIT, received: {}", tokens[i].VALUE);
                }
                
                retFunc.TYPE_SIZE = tokens[i].VALUE.parse::<u16>().unwrap();
            }
            
            if !type_size {
                panic!("Expected ValueType, but received: {}, t={}", tokens[i].VALUE, i);
            }
            
            i += 1;
            
            if !(tokens[i].TYPE != TokenType::UNKNOWN || tokens[i].TYPE != TokenType::NAME) {
                panic!("Cannot use {} for function name", tokens[i].VALUE);
            }
            
            tokens[i].TYPE = TokenType::NAME;
            retFunc.NAME = tokens[i].VALUE.clone();
            
            /* TODO: Once we need to start working with params, insert the impl here */
            
            i += 2;
            
            if tokens[i].TYPE != TokenType::RPAREN {
                panic!("Params have not been impl yet, c={} and t={}", tokens[i].VALUE, i);
            }
            
            i += 1;
            
            if tokens[i].TYPE != TokenType::LBRACE {
                panic!("Expected LBRACE, received {}", tokens[i].VALUE);
            }
            
            while tokens[i].TYPE != TokenType::RBRACE {
                i += 1;
                
                if tokens[i].TYPE == TokenType::SEMI {
                    continue;
                }
                
                retFunc.INSTRUCTS.push(tokens[i].clone());
            }
            functions.push(retFunc);
        }
        
        i += 1;
    }
    
    for i in 0 .. tokens.len() {
        if tokens[i].TYPE == TokenType::UNKNOWN {
            panic!("Unknown object: {}", tokens[i].VALUE);
        }
    }
    
    dbg_tokens(&tokens);
    println!("--------------");
    dbg_func(&functions);
    
    /* Start compiling at the main function */
    
    
    let mut funcLoc = 0;
    let mut mainFunc: isize = -1;
    let mut outFile = File::create("out.s");
    
    for i in 0 .. functions.len() {
        if functions[i].NAME == "main" {
            mainFunc = i as isize;
        }
    }
    
    if mainFunc == -1 {
        panic!("Could not find main function!");
    }
    
    for i in 0 .. functions[mainFunc as usize].INSTRUCTS.len() {
        if functions[mainFunc as usize].INSTRUCTS[i].TYPE == TokenType::EXIT {
            if functions[mainFunc as usize].INSTRUCTS[i + 1].TYPE != TokenType::INT_LIT {
                panic!("Expected INT_LIT, but received: {}", functions[mainFunc as usize].INSTRUCTS[i + 1].TYPE as i32);
            }
            
            println!("Exit {}", functions[mainFunc as usize].INSTRUCTS[i + 1].VALUE);
        }
    }
    
    Ok(())
}

fn tokenize(contents: &String, tokens: &mut Vec<Token>) {
    let _contentVal: Vec<u8> = contents.as_bytes().to_vec();
    let mut contentVal: Vec<char> = Vec::new();
    let mut i = 0;
    let mut buf: &mut String = &mut String::new();
    let mut contentVal: Vec<char> = Vec::new();
    
    for j in 0 .. _contentVal.len() {
        contentVal.push(_contentVal[j] as char);
    }
    
    while i < contents.len() {
        buf.clear();
        let mut c = contentVal[i];
        i += 1;
        
        if c == ' ' {
            continue;
        }
        
        if c.is_alphanumeric() || c == '_' {
            i-=1;
            while i < contents.len() {
                c = contentVal[i];
            
                if !isalpha(c) && c != '_' {
                    break;
                }
            
                buf.push(c);
                i+=1;
            }
            
            tokens.push(Token {
                VALUE: buf.to_string(),
                TYPE: TokenType::UNKNOWN,
            });
            
            continue;
        }
        
        if c.is_digit(10) {
            i-=1;
            while i < contents.len() {
                c = contentVal[i];
            
                if !c.is_digit(10) {
                    break;
                }
            
                buf.push(c);
                i+=1;
            }
            
            tokens.push(Token {
                VALUE: buf.to_string(),
                TYPE: TokenType::INT_LIT,
            });
            
            continue;
        }
        
        if c == '\n' {
            tokens.push(Token {
                VALUE: "\n".to_string(),
                TYPE: TokenType::NEWLINE,
            });
            
            continue;
        }
        
        if c == ';' {
            tokens.push(Token {
                VALUE: ";".to_string(),
                TYPE: TokenType::SEMI,
            });
            
            continue;
        }
        
        if c == '{' {
            tokens.push(Token {
                VALUE: "{".to_string(),
                TYPE: TokenType::LBRACE,
            });
            
            continue;
        }
        
        if c == '}' {
            tokens.push(Token {
                VALUE: "}".to_string(),
                TYPE: TokenType::RBRACE,
            });
            
            continue;
        }
        
        if c == '(' {
            tokens.push(Token {
                VALUE: "(".to_string(),
                TYPE: TokenType::LPAREN,
            });
            
            continue;
        }
        
        if c == ')' {
            tokens.push(Token {
                VALUE: ")".to_string(),
                TYPE: TokenType::RPAREN,
            });
            
            continue;
        }
        
        if c == ':' {
            tokens.push(Token {
                VALUE: ":".to_string(),
                TYPE: TokenType::COLON,
            });
            
            continue;
        }
        
        /* TODO: find out what to do here, cuz IDK what yet, so just panic for now */
        panic!("Unknown object: {} ({}) at c={}", c, c as u8, i);
    }
}

fn dbg_tokens(tokens: &Vec<Token>) {
    for i in 0 .. tokens.len() {
        if tokens[i].TYPE == TokenType::NEWLINE {
            println!("Value: \\n, Type: {}", tokens[i].TYPE as i32);
            continue;
        }
        println!("Value: {}, Type: {}", &tokens[i].VALUE, tokens[i].TYPE as i32);
    }
}

fn dbg_func(funcs: &Vec<Function>) {
    for i in 0 .. funcs.len() {
        println!("Name: {}, Type: {}, Type_size: {}, Location: {}", funcs[i].NAME, funcs[i].TYPE as i32, funcs[i].TYPE_SIZE, funcs[i].LOCATION);
    }
}

struct Function {
    NAME: String,
    TYPE: ValueType,
    TYPE_SIZE: u16,
    PARAM: Vec<ValueType>,
    PARAM_SIZE: Vec<u16>,
    INSTRUCTS: Vec<Token>,
    LOCATION: u64,
}

#[derive(Clone)]
struct Token {
    VALUE: String,
    TYPE: TokenType,
}

#[derive(PartialEq, Copy, Clone)]
enum ValueType {
    INT,
    CHAR,
    VOID,
    UNKNOWN,
}

impl ValueType {
    fn from_i32(value: i32) ->
    ValueType {
        match value {
            0 => ValueType::INT,
            1 => ValueType::CHAR,
            2 => ValueType::VOID,
            _ => ValueType::UNKNOWN,
        }
    }
}

#[derive(PartialEq, Copy, Clone)]
enum TokenType {
    EXIT,
    FN,
    INT,
    CHAR,
    VOID,
    NAME,
    INT_LIT,
    SEMI,
    COLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    NEWLINE,
    UNKNOWN,
}

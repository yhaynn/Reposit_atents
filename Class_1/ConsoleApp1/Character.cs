using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//추가적인 기능을 사용할 것인지 표시하는 것


// namespace : 이름이 겹치는것을 방지하기 위해 구분지어놓은 용도
namespace ConsoleApp1
{
    //internal: 같은 어셈블리안에서는 public 다른 어셈블러라면 private

    //접근제한자(Access Modifier) 
    // public : 누구든지 접근할수 있다  ***
    // private : 자기 자신이나 같은 멤버만 접근할 수 있다 ***
    // protected : 자기과 자신을 상속받은 자식만 접근할 수 있다. ***
    // internal : 같은 어셈블리 안에서는 publick 다른 어셈블리면 private

   
    
    
    public class Character // Character 라는 클래스를 public으로 선언한다.(틀을 만들었다) rpg 게임을 예시로 보자(폴아웃?)

        //class 사용법은 사용할 프로젝트에서 
    {
        //멤버변수 ->데이터
        protected int hp; //C#에서는 기본적으론 private다. 따라서 hp만 public int hp 하면 program 프로젝트에서 사용가능하다
        protected int maxHp; //protected로 상속받는 자식 프로젝트가 접근 가능해짐
        protected int stamina;
        protected int strength;
        protected int precision;
        protected int endurance;
        protected int charisma;
        protected int intelligence;
        protected int agility;
        protected int luck;
        protected string name;

        public string Name => name;

        //배열 : 같은 종유(데이터타입)의 데이터를 한번에 여러개 가지는 유형의 변수
        // int[] intArray; //인티저를 여러개 가질수 있는 배열
        // intArray = new int[5]; //인티저를 5개 가질 수 있도록 생성
        
        
        string[] nameArray = { "플레이어", "동료", "적", "상인", "보스" }; //nameArray에 기본값 설정(선언과 동시에 할당)
        protected Random rand;


        public int HP
        {
            get
            {
                return hp; //이 프로퍼티를 읽을때 호출되는 부분. get만 만들면 읽기 전용

            }

            set
            {
                hp = value; // 이 프로퍼티에 값을 넣을때 호출되는 부분. set 앞에 private를 입력시 나만 쓰는것이 가능.

                if(hp > maxHp)
                {
                    hp = maxHp;
                }

                if(1< hp )
                {
                    Turn_change();

                }

                else if(hp <= 0)
                {
                    Console.WriteLine($"{name}이/가 사망하였습니다"); //사망 처리 함수 호출
                    
                }
            }
        }

        public Character()
        {
            Console.WriteLine($"{name}");
            rand = new Random(DateTime.Now.Millisecond);
            int randomNumber = rand.Next();
            randomNumber %= 5;                  //randomNumber = randomNumber % 5;
            name = nameArray[randomNumber];    //랜덤, 모듈레이터

            Generate_Stat();            
            //TestPrintStatus();
            

            //Random rand2 = new Random();
            //rand2 = new Random();

            //실습
            //1. 이름이 있는 nameArray에 들어있는 것 중 하나로 랜덤하게 선택된다.
            //2. maxHP는 100~200 사이로 랜덤하게 선택된다.
            //3. hp는 maxHp와 같은 값이다.
            //4. 스텟 값은 1~20사이 랜던하게 정해진다.
            //5. Testprintstatys 함수를 이요해 최종 상태를 출력한다.





        }

        public Character(string newName2)
        {
           
            rand = new Random(DateTime.Now.Millisecond);
            Console.WriteLine($"{newName2}");
            name = newName2;

            Generate_Stat();
            TestPrintStatus();
        }
        

        public virtual void Generate_Stat()
        {
            //hp
            maxHp = rand.Next(100, 201);
            hp = maxHp;

            //stat

            strength = rand.Next(20) + 1;
            precision = rand.Next(20) + 1;
            endurance = rand.Next(20) + 1;
            charisma = rand.Next(20) + 1;
            agility = rand.Next(20) + 1;
            intelligence = rand.Next(20) + 1;
            luck = rand.Next(20) + 1;

            
        }


        //멤버함수 -> 기능
        public virtual void Attack(Character target)
        {
            int damage = strength;
            target.TakeDamage(damage);
            Console.WriteLine($"{name}이/가 {target.name}에게 공격합니다.(공격력 : {damage})");
        }

        public void TakeDamage(int damage)
        {
            HP -= damage;
            Console.WriteLine($"2*{name}은/는 {damage}만큼의 피해를 입었습니다.");
        }

        
        public virtual void TestPrintStatus()
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine($"┃인지\t:\t{precision}");
            Console.WriteLine($"┃인내\t:\t{endurance}");
            Console.WriteLine($"┃매력\t:\t{charisma}");
            Console.WriteLine($"┃지능\t:\t{intelligence}");
            Console.WriteLine($"┃민첩\t:\t{agility}");
            Console.WriteLine($"┃행운\t:\t{luck}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");

        }


        public void Turn_change()
        {
            Console.WriteLine("\n공수 전환\n");
        }

        

    }
}

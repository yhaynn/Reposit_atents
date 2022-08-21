using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        //스코프(scope): 변수나 함수를 사용할 수 있는 범위. 변수를 선언한 시점에서 해당 변수가 포함된 중괄호가 끝나는 구간까지
        static void Main(string[] args)
        {



            //실습
            //Human의 testprintstatues함수를 오버라이드(원래 함수의 기능을 다른 기능으로 변경하는것) (mp출력)
            //Human의 attack 함수를 오버라이드 하라. 1)공격시 30%확률로 치명타(데미지2배)  //2시20분까지




            //int sumResult = Sum(20, 30);
            //Console.WriteLine($"SumResult : {sumResult}");

            //Print();

            //Test_base_stat_Fuction();



            //bool b1= true;
            //bool b2= false;
            //논리연산자
            // && (and) :t && t = t 둘다 참일때만 참. 
            // || (or)  : 둘 중 하나만 참이어도 참
            // ~ (not) : 뒤집는것. ~t = f, ~f = t/



            Human human1 = new Human(); //test 프로젝트에서 class 할당 완료. instance화. 객체(object) 생성 완료(객체의 인스턴스를 만들었다)
            Human human2 = new Human("보스"); //Character 타입으로 하나 더 만든것. human1와 human2는 서로 다른 개체다(할당된 메모리가 다르다)


            
            //Human h1 = new Human();  //
            //Character c1 = h1;      //상속받은 클래스는 부모타입 클래스 타입으로 실행된다
            //c1.TestPrintStatus(); //character의 testprintstatus 호출이 된다.
            //c1.Generate_Stat();  //Human의 generate 함수가 실행된다.



            Deathmatch(human1, human2);


            Console.ReadKey();                   
        }

        private static void Deathmatch(Character human1, Character human2)
        {
            while (human1.HP > 0 || human2.HP > 0)
            {
                Turn_Fight(human1, human2);
                Console.WriteLine("─────턴 종료─────");

                if (human1.HP < 1 || human2.HP < 1)
                {
                    if (human2.HP < 1)
                    {
                        Console.WriteLine("/////////////////전투 종료/////////////////");
                        break;
                    }
                    Console.WriteLine("/////////////////전투 종료/////////////////");
                    break;
                }
            }
        }

        private static void Turn_Fight(Character human1, Character human2)
            {
                human1.Attack(human2);
                human1.TestPrintStatus();
                human2.TestPrintStatus();
                human2.Attack(human1);
                human1.TestPrintStatus();
                human2.TestPrintStatus();
            }

            //private static void Check_hp(Character human1, Character human2)
            //{
            //    if (human1.HP != 0)
            //    {
            //        Turn_Fight(human1,human2);

            //    }
            //    else if(human2.HP != 0)
            //    {
            //        Turn_Fight(human1 ,human2);
            //    }

            //    else if(human1.HP == 0)
            //    {
            //        Console.WriteLine("1플래이어 패배");
            //    }

            //    else if(human2.HP == 0)
            //    {
            //        Console.WriteLine("2플레이어 패배");
            //    }

            //    else
            //    {
            //        Turn_Fight(human1,human2);
            //        Console.WriteLine("계속 싸웁니다");
            //    }
            //}


            //Random random = new Random(); //
            //for(int i = 0; i < 5; i++)
            //{
            //Random[] nameArray = new Random(); 
            //    //% 앞에 숫자를 뒤의 숫자로 나눈 나머지값을 돌려주는 연산자.(모듈레이트 연산, 나머지 연산)
            //    //10%3하면 결과는 1
            //    //연산의 결과는 항상 0~(뒷 숫자 -1)로 나온다.



            //Console.WriteLine($"이름 : {human}");

            //}
            private static void GuGudan()
        {
            //실습
            //1.int 타입의 파라메터를 하나 받아서 그 숫자에 해당하는 구구단을 출력해주는 함수 만들기  반복문-
            //2.1번에서 만드는 함수는 2~9까지 입력이 들어오면( 1< a <10) 해당 구구단 출력. 그외의 수는 잘못된 입력입니다 문구 출력.  -조건문
            //3.메인 함수에서 숫자를 하나 입력받는 코드가 있어야 한다.
            Console.WriteLine("숫자를 입력하세요. (2~9)");

            string tempNum = Console.ReadLine();
            int a = 0;
            int.TryParse(tempNum, out a);
            GUGU(a);
        }

        private static void GUGU(int in_num)
        {
            if (1 < in_num && in_num < 10)  //<=나 >=는 두개의 조건이 결합된것이므로 가능한 피하는것이 좋다.
            {

                Console.WriteLine("구구단 출력");
                for (int i = 1; i < 10; i++)
                {
                    Console.WriteLine($"{in_num} * {i} = {in_num * i}");
                }



            }
            else
                {
                    Console.WriteLine("잘못된 입력입니다.");
                }
            
           
        }

       
        private static void Test_base_stat_Fuction()
        {
            string name2 = "너굴맨";
            int level = 2;
            int hp = 10;
            int maxHP = 20;
            float exp = 0.1f;
            float maxExp = 1.0f;

            PrintCharacter(name2, level, hp, maxHP, exp, maxExp);
        }

        //실습: 파라메터로 받은 데이터를 적당한 양식으로 출력해주는 함수 완성하기.
        private static void PrintCharacter(string name, int level, int hp, int maxHP,float exp, float maxExp)
        {
            Console.WriteLine($"┏ 이름\t : {name}");
            Console.WriteLine($"┃ 레벨\t : {level}");
            Console.WriteLine($"┃ HP\t : {hp}/{maxHP}"); //:d3 0으로 빈자리  ,3 스페이스로 빈자리   string format 참고
            Console.WriteLine($"┖ EXP\t : {exp}/{maxExp}");
            




            Console.ReadKey();
        }






        //함수
        //이름: 함수들을 구분하기 위한 이름
        //리턴 타입: 함수의 실행 결과를 돌려주는 데이터의 타입(int, 함수 이름의 앞에 표시된다.
        //파라메터(매개변수): 함수가 실행될때 외부에서 받는 값(아래 예제의 int a와 int b. 함수 이름 뒤에 표시
        //함수 바디: 함수가 호출될때 실행될 코드들
        //이름+리턴타임+파라메터= 함수 프로토타입. 주민번호 같은것. 하나의 프로젝트안에 절대 겹쳐지지 않는다

        static int Sum(int a, int b)
        {
            int result = a + b;
            return result;
        }

        void Print() //리턴값도 없고 파라메터도 없음
        {
            Console.WriteLine ("print");
        }

        void Test()
        {
            // Console.WriteLine("Hello World!"); //Helloworld 출력코드
            // Console.WriteLine("양해인");       //이름 출력 코드
            //string str = Console.ReadLine();     //키보드 입력을 받아서 str이라는 string변수를 받아들인다.


            /*변수의 종류
             int 인티저.정수, 소수점이 없는 수
             float 플로트. 실수, 소수점이 있는 수
             string 스트링. 문자열,글자
             bool 불 or 불리언. 참true과 거짓false를 저장*/

            /*int a = 10;
            long b = 500000000;

            float aa = 0.00001f; //float 단점은 오차가 발생한다
            float bb = 0.00009f;

            float cc= aa+bb;
            Console.WriteLine(cc);

            string str1 = "Hello";//string은  스트링간의 +가 가능하다
            string str2 = "안녕";
            string str3 = $"Hello {a}";
            Console.WriteLine(str3);    
            string str4 = str1 + str2;
            Console.WriteLine(str4);

            bool b1 = true;
            bool b2 = false;*/

            string name = "삼색이";
            string race = "Cat";
            string address = "양어장";
            int age = 4;
            float weight = 3.33f;
            double stat_cute = 999.99;
            float exp = 0.401f;
            float stat_courage = 0.02f;
            int hp = 1;

            /*Console.WriteLine("이름: "+name);  
            Console.WriteLine("종족: "+race);
            Console.WriteLine("거주지: "+address);
            Console.WriteLine("체력: "+weight);
            Console.WriteLine("용기: "+stat_courage);
            Console.WriteLine("귀여움: "+stat_cute);
            Console.WriteLine("경험치: "+ exp +"/100");


            string result = $"{name}의 종족은 {race}이고 약 {age}살이며 {address}에 산다.\n놀랍게도 {weight}kg이며용기는 {stat_courage}만큼이지만 귀여움은 {stat_cute*100:F1}%다."; // 줄바꿈은 \n
            Console.WriteLine(result);
            */





            //입출력 실습
            Console.Write("이름을 입력하세요: ");
            name = Console.ReadLine();

            Console.Write($"{name}의 나이를 입력하세요: ");
            string temp = Console.ReadLine();
            age = int.Parse(temp); //  string을 int로 변경해주는 코드(숫자로 바꿀수 있을때만). 간단하지만 위험
            //level = Convert.ToInt32(temp); 이것도 위험
            //int.TryParse(age, out level); // 숫자로 바꿀수 없으면 0으로 출력

            Console.Write($"{name}의 체중(kg)을 입력하세요: ");
            string Temp = Console.ReadLine();
            weight = float.Parse(Temp);

            Console.Write($"{name}는 얼마나 귀여운지 입력하시오: ");
            string temp2 = Console.ReadLine();
            stat_cute = double.Parse(temp2);

            string result2 = $"{name}의 나이는 {age}살이고 {weight}kg이지만 {stat_cute:F2}%만큼 귀엽다.";
            Console.WriteLine(result2);



            //제어문. 실행되는 코드 라인을 변경할 수 있는 코드. 기본적으로 코드는 위에서 위에서 아래로 순차 실행 된다

            if (weight > 3)
            {
                string result_heavy = $"{name}은 뚱냥이입니다.";
                Console.WriteLine(result_heavy);
            }

            else if (weight < 3)
            {
                string result_light = $"{name}은 마른 냥이입니다.";
            }

            else
            {
                string result_fair = $"{name}는 적당합니다";
                Console.WriteLine(result_fair);
            }

            switch (weight)
            {
                case 1:
                    Console.WriteLine();
                    break;

                case 2:
                    Console.WriteLine();
                    break;

                case 3:
                    Console.WriteLine();
                    break;


            }

            /*조건문
            Console.Write("경험치를 추가합니다.");
            Console.WriteLine($"{exp}");
            Console.WriteLine("추가할 경험치: ");
            string tempAdd = Console.ReadLine();

            float tempExp;
            float.TryParse(tempAdd, out tempExp);

            
            if ((exp+tempAdd) >= 1f){
                Console.WriteLine("레벨 업");
            }

            else if (exp+tempAdd < 0);
            {
                Console.WriteLine($"현재 경험치 : {exp+tempExp}");
            //string temp = Console.ReadLine();

            }*/


            //경험치와 추가 경험치의 합이 1 이상이면 레벨업, 1미만이면 합계 출력



            ///반복문
           
            int level = 1;
            while (level < 3)
            {
                Console.WriteLine($"현재 레벨 : {level}");
                level++;
            }

            //level += 2; //level에 2를 더해서 레벨에 넣어라

            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine($"현재 hp : {hp}");
                hp += 10;

            }


            do
            {
                Console.WriteLine($"현재 레벨 : {hp}");
                if (level == 2)
                {
                    break;
                }

                level++;
            }
            while (level < 10);
            {
                Console.WriteLine($"최종 레벨 : {level}");

            }
            //실습 exp가 1을 넘어 레벨업을 할때까지 계속 추가 경험치를 입력하도록 하는 코드 작성




            float exp2 = 0.0f;
            Console.WriteLine($"현재 경험치 : {exp2}");


            while (1.0f > exp2)
            {

                Console.WriteLine("경험치를 추가합니다.");
                Console.WriteLine("추가할 경험치: ");
                string tempLv = Console.ReadLine();

                float tempv = 0.0f;
                float.TryParse(tempLv, out tempv);

                exp2 += tempv;


            }

            Console.WriteLine("레벨 업");
        }
    }
}

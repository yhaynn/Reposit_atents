﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


////해야할것: 공수 과정이 제대로 안됨. 휴먼 스킬 추가,오크 스킬 수차
namespace ConsoleApp1
{
    internal class Program
    {
        
        static void Main(string[] args)
        {

            //Human human1 = new Human(); //test 프로젝트에서 class 할당 완료. instance화. 객체(object) 생성 완료(객체의 인스턴스를 만들었다)
            //Human human2 = new Human("보스"); //Character 타입으로 하나 더 만든것. human1와 human2는 서로 다른 개체다(할당된 메모리가 다르다)


            //Human player = new Human();

            Human player;
            Console.WriteLine("당신의 이름을 입력하세요");
            string name = Console.ReadLine();
            string result;
            do
            {
                player = new Human(name);
                Console.WriteLine("이대로 진행하시겠습니까? (yes/no): ");
                result = Console.ReadLine();
            }
            while (result != "yes" && result !="Yes"&&result!="y"&&result!="Y");


            Orc orc1 =new Orc("굴라크");

            Console.WriteLine($"오크 {orc1.Name}가 나타났다.");

            
            //Character c1 = h1;      //상속받은 클래스는 부모타입 클래스 타입으로 실행된다
            //c1.TestPrintStatus(); //character의 testprintstatus 호출이 된다.
            //c1.Generate_Stat();  //Human의 generate 함수가 실행된다.

            Console.WriteLine("\n-------------전투를 시작합니다-------------\n");

            Deathmatch(player, orc1);


            Console.ReadKey();
        }

        private static void Deathmatch(Character player, Character orc1)
        {
            while (true)    //while(true)문은 무한루프.
            {
                
                Turn_Fight(player, orc1);
               
                
                if (orc1.HP<1 && player.HP < 1)         //동시사망 고려
                {
                    Console.WriteLine("승부가 나지 않았습니다.");
                    break;
                }
                else if (player.HP < 1 || orc1.HP < 1)
                {
                    if (orc1.HP < 1)
                    {
                        Console.WriteLine("/////////////////오크 사망.전투 종료/////////////////");  
                        break;
                    }


                    else if (player.HP < 1)
                    {
                        Console.WriteLine("///////////////// 오크 승리.전투 종료/////////////////");
                        break;
                    }
                }
            }
        }

        public static void Turn_Fight(Character player, Character orc1)
        {
            player.Attack(orc1);        //플레이어 공격
            player.TestPrintStatus();   //플레이어 상태창
            orc1.TestPrintStatus();     //오크 상태창
            Console.WriteLine("\n\n");  //공란
            orc1.Attack(player);        //오크 공격
            player.TestPrintStatus();   //플레이어 상태창
            orc1.TestPrintStatus();     //오크 상태창

            Console.WriteLine("\n─────턴 종료─────\n");  
            
        }

        
    }

}
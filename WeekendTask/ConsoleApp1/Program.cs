﻿using System;
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

            Human human1 = new Human(); //test 프로젝트에서 class 할당 완료. instance화. 객체(object) 생성 완료(객체의 인스턴스를 만들었다)
            //Human human2 = new Human("보스"); //Character 타입으로 하나 더 만든것. human1와 human2는 서로 다른 개체다(할당된 메모리가 다르다)

            Orc orc1 =new Orc("오크");


            //Human h1 = new Human();  //
            //Character c1 = h1;      //상속받은 클래스는 부모타입 클래스 타입으로 실행된다
            //c1.TestPrintStatus(); //character의 testprintstatus 호출이 된다.
            //c1.Generate_Stat();  //Human의 generate 함수가 실행된다.

            Console.WriteLine("\n전투를 시작합니다.\n");

            Deathmatch(human1, orc1);


            Console.ReadKey();
        }

        private static void Deathmatch(Character human1, Character orc1)
        {
            while (human1.HP > 0 || orc1.HP > 0)
            {
                
                Turn_Fight(human1, orc1);
               
                //if (human1.HP > 0)
                //{

                //    return;
                //}

                if (human1.HP < 1 || orc1.HP < 1)
                {
                    if (orc1.HP < 1)
                    {
                        Console.WriteLine("/////////////////오크 사망.전투 종료/////////////////");
                        break;
                    }


                    else if (human1.HP < 1)
                    {
                        Console.WriteLine("///////////////// 오크 승리.전투 종료/////////////////");
                        break;
                    }
                }
            }
        }

        public static void Turn_Fight(Character human1, Character orc1)
        {
            human1.Attack(orc1);  //휴먼 공격
            human1.TestPrintStatus();   //휴먼 상태창
            orc1.TestPrintStatus();     //오크 상태창
            Console.WriteLine("\n\n");
            orc1.Attack(human1);        //오크 공격
            human1.TestPrintStatus();   //휴면 상태창
            orc1.TestPrintStatus();     //오크 상태창

            Console.WriteLine("\n─────턴 종료─────\n");
        }

        
    }

    
}
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Human : Character  //human 클래스는 character 클래스를 상속받았다.
    {
        

        

        public Human(string player) : base(player)
        {
            name= player;
            Generate_Stat();
            TestPrintStatus();
        }

        //public Human()
        //{
        //    //이게 없으면 public Human(string player) : base(player)만 존재
        //    //자동으로 상속받은 부모의 생성자도 실행
        //}
        public override void Generate_Stat()
        {
            base.Generate_Stat(); //Character의 Genarated_stat 함수 실행
            maxMp = rand.Next() % 100; //추가한 변수만 추가로 처리
            mp = maxMp;

            agility = rand.Next(20) + 1;
        }



        public override void Attack(Character target)
        {
            

            Console.Write("1)공격\t2)스킬\t3)방어\t4)도주\t");
            String SelectNum=Console.ReadLine();
            int num = int.Parse(SelectNum);
            
            switch (num)
            {
                case 1:
                    {
                        Console.WriteLine($"\n[{name}]이/가 공격을 실행합니다.\n");

                        int damage = strength;

                        target.TakeDamage(damage);
                        Console.WriteLine($"일반[{name}]이/가 [{target.Name}]에게 공격을 합니다.(공격력 : {damage})");

                        if (rand.NextDouble() < 0.3f)
                        {


                            {
                                damage *= 2;
                                Console.WriteLine($"*크리티컬 히트");

                            }
                            target.TakeDamage(damage);
                            Console.WriteLine($"크리[{name}]이/가 [{target.Name}]에게 공격을 합니다.(공격력 : {damage})\n[{target.Name}]은/는 {damage}만큼 피해를 입었습니다.");  //이 줄 정리}
                        }
                        break;
                    }
                case 2:
                    {
                        Console.WriteLine($"\n[{name}]이/가 스킬을 사용합니다.\n");
                        Human_heal();
                        break;
                    }
                case 3:
                    {
                        Console.WriteLine($"{name}이/가 방어합니다.");
                        Defense();

                        break;
                    }
                case 4:
                    {
                        Console.WriteLine($"\n[{name}]이/가 도주합니다...\n");
                        Human_dodge();
                        break;
                    }
                default:
                    break;


            }

        }


        public override void TakeDamage(int damage)
        {

            if (rand.NextDouble() < 0.3f)
            {
                if (agility > damage)
                {
                    HP -= damage / 4;
                    Console.WriteLine($"[{name}]은 공격을 회피하여 {damage / 4}만큼의 피해로 빗맞았습니다.");  //민첩수치가 데미지보다 높으면(?) 1/4만큼 데미지를 감소하여 받는다.

                }
            }
            else { 
            HP -= damage;
            //Console.WriteLine($"1[{name}]은/는 {damage}만큼의 피해를 입었습니다.");
            }
        }
            
                    
                

        




        public void Human_heal()
        {
            if (mp > 5)
            {
                Console.WriteLine($"{name}의 hp를 회복합니다.");
                HP += 20;
                mp -= 5;
            }

            else
            {
                Console.WriteLine("MP 부족으로 회복할 수 없습니다.\n무리한 시도로 행동할 수 없습니다.");

            }
        }


        public void Target_Skill()
        {
            int damage = (int)(((rand.NextDouble() * 2.5f) + 1) * intelligence); //지능의 1~2.5배한 결과에서 소수점을 제거한 범위내에서
            
        }
        public void Human_dodge()
        {
            Console.ReadKey();
            Environment.Exit(0);
        }
        public override void TestPrintStatus()
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃MP\t:\t{mp}/{maxMp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine($"┃민첩\t:\t{agility}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");
        }
    }
}

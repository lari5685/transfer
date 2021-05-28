#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpixmap.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <QRandomGenerator>
#include <QTimer>
#include <sstream>

QRandomGenerator generator;

CRITICAL_SECTION CriticalSection;

HANDLE hThread1, hThread2, hThread3;

int client = 0; DWORD ExitCode;
int randtime1, randtime2, randtime3;


MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        ui->radioButton_2->setChecked(true);
        tmr = new QTimer();
        tmr->setInterval(10);
        connect(tmr, SIGNAL(timeout()), this, SLOT(isCompleted())); // Подключаем сигнал таймера к нашему слоту
        tmr->start();
        InitializeCriticalSection(&CriticalSection);
        client =  QRandomGenerator::global()->bounded(0, 10);
}


MainWindow::~MainWindow()
{
DeleteCriticalSection(&CriticalSection);
delete ui;
}


DWORD CALLBACK Thread1(void* param)
 {
        int c = client;
        while (c > 0) {
        EnterCriticalSection(&CriticalSection);
            --client;
        LeaveCriticalSection(&CriticalSection);
            randtime1 = QRandomGenerator::global()->bounded(5, 10);
            while (randtime1 > 0)
            {
                Sleep(1000);
                randtime1--;
            }
             c = client;
        }
        DWORD result = 1;
        return  result;
 }



DWORD CALLBACK Thread2(void* param)
 {
        int c = client;
        while (c > 0) {
        EnterCriticalSection(&CriticalSection);
            --client;
        LeaveCriticalSection(&CriticalSection);
        randtime2 =  QRandomGenerator::global()->bounded(5, 10);
        while (randtime2>0)
        {
         Sleep(1000);
         randtime2--;
        }
         c = client;
        }
         DWORD result = 2;
         return  result;
 }



DWORD CALLBACK Thread3(void* param)
 {
        int c = client;
        while (c > 0) {
        EnterCriticalSection(&CriticalSection);
            --client;
        LeaveCriticalSection(&CriticalSection);
        randtime3 = QRandomGenerator::global()->bounded(5, 10);
        while (randtime3>0)
        {
         Sleep(1000);
         randtime3--;
        }
        EnterCriticalSection(&CriticalSection);
         c = client;
        LeaveCriticalSection(&CriticalSection);
        }
         DWORD result = 3;
         return  result;
 }



void MainWindow::on_pushButton_clicked()
{


        if (ui->radioButton->isChecked()) {

                ui->label->setText(QString("Касса свободна!"));
                ui->label_2->setText(QString("Касса не работает!"));
                ui->label_3->setText(QString(("Касса не работает!")));

                GetExitCodeThread(hThread1, &ExitCode);
             if (ExitCode != STILL_ACTIVE){

                    HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                    GetExitCodeThread(hThread1, &ExitCode);
                    ui->label_7->setText(QString::number(ExitCode));
                    ui->label_5->setText(QString(("создан")));

             }

                else if  (ExitCode == STILL_ACTIVE)
             {   ui->label_7->setText(QString(("удален и создан ")));
                     TerminateThread(hThread1, ExitCode);
                     CloseHandle(hThread1);
                     WaitForSingleObject(hThread1, INFINITE);
                     HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                     GetExitCodeThread(hThread1, &ExitCode);

             }
        }



         if (ui->radioButton_2->isChecked()) {

                ui->label->setText(QString("Касса свободна!"));
                ui->label_2->setText(QString("Касса свободна!"));
                ui->label_3->setText(QString(("Касса не работает!")));

                GetExitCodeThread(hThread1, &ExitCode);
             if (ExitCode != STILL_ACTIVE){

                    HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                    GetExitCodeThread(hThread1, &ExitCode);
                    ui->label_7->setText(QString::number(ExitCode));
                    ui->label_5->setText(QString(("создан")));

             }

                else if  (ExitCode == STILL_ACTIVE)
             {   ui->label_7->setText(QString(("удален и создан ")));
                     TerminateThread(hThread1, ExitCode);
                     CloseHandle(hThread1);
                     WaitForSingleObject(hThread1, INFINITE);
                     HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                     GetExitCodeThread(hThread1, &ExitCode);

             }



             GetExitCodeThread(hThread2, &ExitCode);
            if (ExitCode != STILL_ACTIVE){

                 HANDLE hThread2 = CreateThread(0,0,Thread2,0,0,NULL);
                 GetExitCodeThread(hThread2, &ExitCode);
                 ui->label_7->setText(QString::number(ExitCode));
                 ui->label_5->setText(QString(("создан")));

            }

             else if  (ExitCode == STILL_ACTIVE)
            {   ui->label_7->setText(QString(("удален и создан ")));
                    TerminateThread(hThread2, ExitCode);
                    CloseHandle(hThread2);
                    WaitForSingleObject(hThread2, INFINITE);
                    HANDLE hThread2 = CreateThread(0,0,Thread2,0,0,NULL);
                    GetExitCodeThread(hThread2, &ExitCode);

            }
        }



        if (ui->radioButton_3->isChecked()) {


                ui->label->setText(QString("Касса свободна!"));
                ui->label_2->setText(QString("Касса свободна!"));
                ui->label_3->setText(QString(("Касса свободна")));

                GetExitCodeThread(hThread1, &ExitCode);
             if (ExitCode != STILL_ACTIVE){

                    HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                    GetExitCodeThread(hThread1, &ExitCode);
                    ui->label_7->setText(QString::number(ExitCode));
                    ui->label_5->setText(QString(("создан")));

             }

                else if  (ExitCode == STILL_ACTIVE)
             {   ui->label_7->setText(QString(("удален и создан ")));
                     TerminateThread(hThread1, ExitCode);
                     CloseHandle(hThread1);
                     WaitForSingleObject(hThread1, INFINITE);
                     HANDLE hThread1 = CreateThread(0,0,Thread1,0,0,NULL);
                     GetExitCodeThread(hThread1, &ExitCode);

             }


             GetExitCodeThread(hThread2, &ExitCode);
            if (ExitCode != STILL_ACTIVE){

                 HANDLE hThread2 = CreateThread(0,0,Thread2,0,0,NULL);
                 GetExitCodeThread(hThread2, &ExitCode);
                 ui->label_7->setText(QString::number(ExitCode));
                 ui->label_5->setText(QString(("создан")));

            }

             else if  (ExitCode == STILL_ACTIVE)
            {   ui->label_7->setText(QString(("удален и создан ")));
                    TerminateThread(hThread2, ExitCode);
                    CloseHandle(hThread2);
                    WaitForSingleObject(hThread2, INFINITE);
                    HANDLE hThread2 = CreateThread(0,0,Thread2,0,0,NULL);
                    GetExitCodeThread(hThread2, &ExitCode);

            }



            GetExitCodeThread(hThread3, &ExitCode);
         if (ExitCode != STILL_ACTIVE){

                HANDLE hThread3 = CreateThread(0,0,Thread3,0,0,NULL);
                GetExitCodeThread(hThread3, &ExitCode);


         }

            else if  (ExitCode == STILL_ACTIVE)
         {
                 TerminateThread(hThread3, ExitCode);
                 CloseHandle(hThread3);
                 WaitForSingleObject(hThread3, INFINITE);
                 HANDLE hThread3 = CreateThread(0,0,Thread3,0,0,NULL);
                 GetExitCodeThread(hThread3, &ExitCode);

         }
}

}

void MainWindow::on_pushButton_2_clicked()
{
        client++;
}



void MainWindow::isCompleted()
{
        int count =0;
            if (ui->radioButton->isChecked()){
                        GetExitCodeThread(hThread1, &ExitCode);
                        DWORD result = WaitForSingleObject(hThread1, 0);

                     if (ExitCode == STILL_ACTIVE)
                     {
                             if (client == 0 & randtime1 <= 0)
                        ui->label->setText(QString("Касса свободна!"));
                             else {
                        ui->label->setText(QString("Касса занята, осталось " + QString::number(randtime1) + QString(" секунд!")));
                        count++; }
                     }
                        GetExitCodeThread(hThread1, &ExitCode);
                        result = WaitForSingleObject(hThread1, 0);

                     if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                            ui->label_7->setText(QString(("1")));
                            TerminateThread(hThread1, ExitCode);
                            CloseHandle(hThread1);    }

}


        if (ui->radioButton_2->isChecked()) {

                GetExitCodeThread(hThread1, &ExitCode);
                DWORD result = WaitForSingleObject(hThread1, 0);

             if (ExitCode == STILL_ACTIVE)
             {
                     if (client == 0 & randtime1 <= 0)
                ui->label->setText(QString("Касса свободна!"));
                     else {
                ui->label->setText(QString("Касса занята, осталось " + QString::number(randtime1) + QString(" секунд!")));
                count++; }
             }
                GetExitCodeThread(hThread1, &ExitCode);
                result = WaitForSingleObject(hThread1, 0);

             if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                    ui->label_7->setText(QString(("1")));
                    TerminateThread(hThread1, ExitCode);
                    CloseHandle(hThread1);    }



             GetExitCodeThread(hThread2, &ExitCode);
             DWORD res = WaitForSingleObject(hThread2, 0);

            if (ExitCode == STILL_ACTIVE)
            {
                    if (client == 0 & randtime2 <= 0)
             ui->label_2->setText(QString("Касса свободна!"));
                    else {
             ui->label_2->setText(QString("Касса занята, осталось " + QString::number(randtime2) + QString(" секунд!")));
             count++; }
            }
             GetExitCodeThread(hThread2, &ExitCode);
             res = WaitForSingleObject(hThread2, 0);

            if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                 ui->label_7->setText(QString(("1")));
                 TerminateThread(hThread2, ExitCode);
                 CloseHandle(hThread2);    }
        }




        if (ui->radioButton_3->isChecked()) {
                GetExitCodeThread(hThread1, &ExitCode);
                DWORD result = WaitForSingleObject(hThread1, 0);

             if (ExitCode == STILL_ACTIVE)
             {
                     if (client == 0 & randtime1 <= 0)
                ui->label->setText(QString("Касса свободна!"));
                     else {
                ui->label->setText(QString("Касса занята, осталось " + QString::number(randtime1) + QString(" секунд!")));
                count++; }
             }
                GetExitCodeThread(hThread1, &ExitCode);
                result = WaitForSingleObject(hThread1, 0);

             if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                    ui->label_7->setText(QString(("1")));
                    TerminateThread(hThread1, ExitCode);
                    CloseHandle(hThread1);    }


             GetExitCodeThread(hThread2, &ExitCode);
             DWORD res = WaitForSingleObject(hThread2, 0);

            if (ExitCode == STILL_ACTIVE)
            {
                    if (client == 0 & randtime2 <= 0)
             ui->label_2->setText(QString("Касса свободна!"));
                    else {
             ui->label_2->setText(QString("Касса занята, осталось " + QString::number(randtime2) + QString(" секунд!")));
             count++; }
            }
             GetExitCodeThread(hThread2, &ExitCode);
             res = WaitForSingleObject(hThread2, 0);

            if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                 ui->label_7->setText(QString(("1")));
                 TerminateThread(hThread2, ExitCode);
                 CloseHandle(hThread2);    }


            GetExitCodeThread(hThread3, &ExitCode);
            DWORD resu = WaitForSingleObject(hThread3, 0);

         if (ExitCode == STILL_ACTIVE)
         {
                 if (client == 0 & randtime3 <= 0)
            ui->label_3->setText(QString("Касса свободна!"));
                 else {
            ui->label_3->setText(QString("Касса занята, осталось " + QString::number(randtime3) + QString(" секунд!")));
            count++; }
         }
            GetExitCodeThread(hThread3, &ExitCode);
            res = WaitForSingleObject(hThread3, 0);

         if (ExitCode != STILL_ACTIVE & result == WAIT_OBJECT_0) {

                ui->label_7->setText(QString(("1")));
                TerminateThread(hThread3, ExitCode);
                CloseHandle(hThread3);    }
        }


        ui->label_6->setText(QString("Занятые клиенты: " + QString::number(count)));
        ui->label_4->setText(QString("Общее количество клиентов: " + QString::number(client)));

}


// 1 зуб = 2 полупериодам, т.к. полупериод - это время между сигналами 0 и 1. 2 таких сигнала и составляют импульс, т.е. 1 зуб
// при 36-зубной шестерни вала, 200 об/мин возможны на полупериоде = 4.2 мс, 5000 об/мин - при 0.168 мс
// при 60-зубной шестерни вала, 200 об/мин возможны на полупериоде = 2.5 мс, 5000 об/мин - при 0.1 мс
// при 60 зубах на шестерне коленвала 1 оборот происходит за 72 мс
// при 36 зубах на шестерне коленвала 1 оборот происходит за 43.2 мс

int gear = 60;                  // кол-во зубов шестрени вала
int poluperiod;               // полупериод (мкс)

void setup()  
{
   pinMode(2, OUTPUT);          // 2 пин назначен на выдачу импульсов
   pinMode(A1, INPUT);          // к входу A1 подключаем потенциометр
}

void loop() {
  int val = analogRead(A1);                       // считываем данные с порта A1 (значения потенциометра от 0 до 1023)
  if (gear == 60){                                // для шестерни с 60 зубами
    poluperiod = map(val, 0, 1023, 2500, 100);     // переводим val в новый диапазон от 2500 мкс до 100 мкс и присваиваем знаение потенциометра полупериоду
  }else if(gear == 36){                           // для шестерни с 36 зубами
    poluperiod = map(val, 0, 1023, 4200, 168);   // переводим val в новый диапазон от 4200 мкс до 168 мкс
  }
   
  for(int a=1; a <= gear - 2; a++){               // gear - 2 - отнимаем 2 пропущенных зуба от кол-ва зубов шестерни
    digitalWrite(2, HIGH); 
    delayMicroseconds(poluperiod);
    digitalWrite(2, LOW);
    delayMicroseconds(poluperiod);
  }
  delayMicroseconds(poluperiod * 4);                          // кол-во импульсов до задержки в 2 импульса = 2 зуба
}

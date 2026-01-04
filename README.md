<h1 id="en">EN</h1>

<img class="logo-picture" src="/github-picture/logo/logo.png" alt="logo">

<h3>Languages / 多语言</h3>
<a href="#en">English</a>
<a href="#ru-RU">Русский</a>
<a href="#zh-cn">中文</a>

<h2>Let's Get Straight to the Point</h2>
<p>Visual BeautifUL UI is a brand new API built upon GTkmm 4.0. My previous version, Vbui, wasn't exactly a failure, but... let's say it was quite difficult to use. Let me point out a few things even I want to complain about:</p>
<ul>
    <li>😵‍💫Unclear parameters - Functions like text("hello", 20, 20, false) were frankly laughable. I was too focused on mimicking Flutter's syntax back then and forgot what we really want is a simple, easy-to-use framework.</li>
    <li>🤮Poor extensibility - Vbui v1.0 offered terrible support for multi-function collaboration. When trying to delete code, we'd be stuck with confusing closing brackets like ),20,false) that made it a headache to figure out where to delete from.</li>
    <li>🤔Terrible maintainability - Related to the point above, deletion was hard. Not only was deletion difficult, but finding parameters was also a pain. While coding, we couldn't clearly know what parameters to use next, making the experience frustrating for both individual developers and teams. This has been completely solved in Visual BeautifUL UI Framework 2026 with chainable method calls.</li>
</ul>

<h2>Has the New Version Solved These Issues?</h2>
<p>Yes! The new version uses chainable method calls with RAII patterns instead of single-function calls with obscure parameters. Parameters are now explicit rather than being in a "black box." While it might not be as concise in naming, with IDE autocomplete it's actually quite pleasant to write.</p>

<h4>What from the old API was kept? 🤔</h4>
<p>Yes, I kept something important from the old version! The elegant std::vector<> syntax that makes the API look clean.</p>

<h4>What's new in the Rebirth Edition? 🤔</h4>
<p>Beyond the major API overhaul, I've added function separation for better collaboration. Future plans include adding something similar to JavaScript's FetchAPI for frontend-backend interaction, and a package management system with categorized folders instead of dumping all header files in one directory. This makes importing and remembering components much more convenient. I'm committed to long-term maintenance, though it's tiring for one person. I hope more Linux enthusiasts can join and contribute! Since this is early in the rewrite, many components aren't complete yet - please bear with us. Wishing everyone a great new year with improved coding skills!</p>

<h2>Quick Start with the New Version</h2>

```cpp
#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/ReactiveText.h"
#include "../src/TextComponent/HtmlText.h"
#include "gtkmm/widget.h"

using namespace std;
using namespace Gtk;
using namespace VisualUI;

int main () {
    VisualUI::Application()
        .SetAppID("myapp")
        .SetAppName("myapp")
        .SetAppTitle("hello world")
        .SetWindowSize(600, 400)
        .CreateContent([]() -> Widget*{
            BlockLayoutColumns blocklayout;
            MAKE_COMPONENT(ReactiveComponentText, newReactiveText);
            MAKE_COMPONENT(ButtonComponent, NewButton);
            MAKE_COMPONENT(HtmlText, newHtmlText)
            return blocklayout
                .SetLayoutHeight(200)
                .SetLayoutWidth(200)
                .CreateBlockLayout({
                    newReactiveText
                        .SetDefaultText("hello world")
                        .SetStyleName("default-txt")
                        .addComponent(),
                    newHtmlText
                        .SetHtmlLabel("span")
                        .SetTextColor(COLOR_WHITE)
                        .SetText("Hai Developer!")
                        .SetTextSize(TEXT_SIZE_MEDIUM)
                        .SetFontWeight(TEXT_WEIGHT_BOLD)
                        .SetFontFamily(FONT_JETBRAINS_MONO)
                        .addComponent()
                },[&newReactiveText , &NewButton]()->Gtk::Widget*{
                    NewButton
                        .SetButtonLabel("Click me")
                        .SetButtonAdaption(BUTTON_ADAPTION_WIDTH_FALSE, 
                            BUTTON_ADAPTION_HEIGHT_FALSE)
                            .SetButtonAlign(BUTTON_ALIGN_CENTER)
                            .SetButtonStyle("default-button")
                            .SetButtonMargin(10)
                            .UserClick(true)
                            .Click([&newReactiveText]{
                                newReactiveText.ReactiveText("hai");
                            });
                            return NewButton.addComponent();
                });
        })
        .start();
}
```
<p>Currently, there's limited support. We're working on it! If you'd like to contribute to development or maintenance, contact me at xingxixi335@gmail.com or submit pull requests directly. Any contribution is greatly appreciated! I may not be perfect at this, so guidance from open-source veterans to help with documentation would be wonderful.</p>

<h3>Screenshots from Development (It took a while!)</h3>
<div class="picture-box">
    <img class="picture-style" src="/github-picture/image1.png" alt="Development Screenshot">
    <img class="picture-style" src="/github-picture/image2.png" alt="Development Screenshot">
    <img class="picture-style" src="/github-picture/image3.png" alt="Development Screenshot">
    <img class="picture-style" src="/github-picture/image4.png" alt="Development Screenshot">
    <img class="picture-style" src="/github-picture/image5.png" alt="Development Screenshot">
    <img class="picture-style" src="/github-picture/image6.png" alt="Development Screenshot">
</div>

<h2>Let's Talk About the Framework's Pitfalls</h2>
<ul>
    <li>Don't randomly modify source code - You have no idea how tricky Gtkmm's window lifecycle can be.</li>
    <li>If you find any spelling mistakes in my API, please let me know via issues or pull requests - that's a huge contribution!</li>
    <li>Don't arbitrarily delete components - it can crash your application!!!</li>
</ul>
<p>Thanks in advance for reporting any issues you encounter while using the framework. Active reporting is greatly appreciated!</p>

<h2>My Vision</h2>
<ul>
    <li>I'm fed up with Linux desktop software being buggy - input methods like Fcitx5 acting up, various display bugs, poor adaptation (looking at you, NVIDIA - we all know "so NVIDIA, fu** you" 😂). While the graphics card gets much of the blame, React-based software often has high memory usage, poor underlying adaptation, display issues, or Wayland screen recording/remote desktop crashing. On older hardware, it can freeze or fail to boot entirely. That's reason one.</li>
    <li>Reason two: I want to popularize Linux, making it as common as macOS and Windows, rather than being limited to servers, tech enthusiasts, or computer science students learning Linux servers. If one day Amazon server logs were mostly Linux, I'd wake up laughing! The scarcity of Linux users mainly stems from a lack of everyday software. Many Windows/macOS clients have leisure or professional office software that either doesn't exist for Linux or has terrible adaptations. Naturally, average users won't switch. Gtkmm is open-source but hard to use; Qt isn't free. JavaScript adaptations affect performance. With few Linux users, big companies don't see it as worth supporting. We need a good framework to revive the Linux desktop. It might seem impossible, but let's give it a shot!</li>
</ul>

<h2>About the Author - kwzDev</h2>
<h3>I might seem mysterious 😂</h3>
<p>I'm a pretty unsuccessful middle school student with terrible grades. I'm not interested in any school subjects because they seem useless to me. In Asian society, I feel a degree doesn't guarantee a better job - just an interview opportunity. Many programming graduates end up as delivery drivers without even getting a job.</p>

<h4>More about me 😅</h4>
<p>I really dislike studying. I don't know why - I just can't get into it. I started programming because it felt fun. My first exposure was HTML on short video platforms. Although just a markup language, getting immediate feedback in the browser excited me, so I began learning programming. I don't like learning basics... okay, fine, I did learn Python basics 😂.</p>

<h4>What programming languages have I touched? 🌚</h4>
<ul>
    <li>Python - My first logical programming language, and the only one whose basics I studied. I used it for web scraping and Telegram bots, and Flask for my first backend experience.</li>
    <li>C# - My second package-dependent language. I didn't learn any basics but used ASP.NET Core for backend programs, though just local CRUD with SQLite since I didn't have meaningful API content.</li>
    <li>Java - My third package-dependent language. Without learning basics, I used documentation and AI queries to learn Spring Boot and Android development. I eventually abandoned it due to over-engineering! It's nauseating. I personally hate that design philosophy. I think simple query classes, service configuration, IP rate limiting, logging, and JWT authentication are enough without adding so-called enterprise design to already usable tools!</li>
    <li>C++ - My favorite programming language. I haven't studied extensive basics, just understood pointers and simple OOP concepts (encapsulation, inheritance, polymorphism). I haven't taken courses - just 7 weeks of self-study so far.</li>
</ul>

<h5>I don't consider myself very skilled since most of my code is fairly simple. Except for C++, I haven't delved deep, so I'm not that strong. If I build an official website in the future, I'll use Antao's Drogon framework, not C# or Java. Why? I just don't like programming languages that hide too many details. If you've read this far, thank you for wanting to know more about me!</h5>

<h1>License</h1>
<p>This project is licensed under the <strong>GNU General Public License v3.0 (GPL-3.0)</strong>.</p>
<p>Details can be found in the <a href="LICENSE">LICENSE</a> file.</p>

<h2>License</h2>
<p>This project is licensed under the <strong>GNU General Public License v3.0 (GPL-3.0)</strong>.</p>
<p>See the <a href="LICENSE">LICENSE</a> file for details.</p>

<img class="logo-picture" src="/github-picture/logo/logo.png" alt="logo">

<h3>Языки / Languages</h3>
<a href="#en">English</a>
<a href="#ru-RU">Русский</a>
<a href="#zh-cn">中文</a>

<h2>Сразу к делу</h2>
<p>Visual BeautifUL UI - это совершенно новый API, построенный на основе GTkmm 4.0. Моя предыдущая версия, Vbui, не была полным провалом, но... скажем так, ей было довольно сложно пользоваться. Позвольте мне указать на несколько вещей, на которые даже я хочу пожаловаться:</p>
<ul>
    <li>😵‍💫Неясные параметры - Такие функции, как text("hello", 20, 20, false), были, честно говоря, смешными. Я тогда слишком сосредоточился на имитации синтаксиса Flutter и забыл, что нам действительно нужна простая и удобная в использовании структура.</li>
    <li>🤮Плохая расширяемость - Vbui v1.0 предлагала ужасную поддержку многомодульного взаимодействия. При попытке удалить код мы застревали с запутанными закрывающими скобками, такими как ),20,false), из-за которых было головной болью понять, откуда удалять.</li>
    <li>🤔Ужасная поддерживаемость - Связано с предыдущим пунктом: удаление было сложным. Мало того, что удаление было трудным, но и поиск параметров тоже был мучительным. Во время кодинга мы не могли четко знать, какие параметры использовать дальше, что делало опыт разочаровывающим как для индивидуальных разработчиков, так и для команд. Это полностью решено в Visual BeautifUL UI Framework 2026 с помощью цепочечных вызовов методов.</li>
</ul>

<h2>Решила ли эти проблемы новая версия?</h2>
<p>Да! Новая версия использует цепочечные вызовы методов с шаблонами RAII вместо однострочных вызовов функций с неясными параметрами. Теперь параметры явные, а не находятся в "черном ящике". Хотя это может быть не так лаконично в именовании, с автодополнением IDE писать на самом деле довольно приятно.</p>

<h4>Что было сохранено из старого API? 🤔</h4>
<p>Да, я сохранил кое-что важное из старой версии! Элегантный синтаксис std::vector<>, который делает API чистым.</p>

<h4>Что нового в издании Rebirth? 🤔</h4>
<p>Помимо капитального ремонта API, я добавил разделение функций для лучшего сотрудничества. В планах на будущее - добавление чего-то похожего на FetchAPI из JavaScript для взаимодействия фронтенда и бэкенда, а также система управления пакетами с категоризированными папками вместо сваливания всех заголовочных файлов в один каталог. Это делает импорт и запоминание компонентов гораздо более удобными. Я привержен долгосрочному обслуживанию, хотя для одного человека это утомительно. Я надеюсь, что больше энтузиастов Linux присоединятся и внесут свой вклад! Поскольку это ранний этап переписывания, многие компоненты еще не завершены - пожалуйста, проявите терпение. Желаю всем отличного нового года с улучшенными навыками программирования!</p>

<h2>Быстрый старт с новой версией</h2>

```cpp
#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/ReactiveText.h"
#include "../src/TextComponent/HtmlText.h"
#include "gtkmm/widget.h"

using namespace std;
using namespace Gtk;
using namespace VisualUI;

int main () {
    VisualUI::Application()
        .SetAppID("myapp")
        .SetAppName("myapp")
        .SetAppTitle("hello world")
        .SetWindowSize(600, 400)
        .CreateContent([]() -> Widget*{
            BlockLayoutColumns blocklayout;
            MAKE_COMPONENT(ReactiveComponentText, newReactiveText);
            MAKE_COMPONENT(ButtonComponent, NewButton);
            MAKE_COMPONENT(HtmlText, newHtmlText)
            return blocklayout
                .SetLayoutHeight(200)
                .SetLayoutWidth(200)
                .CreateBlockLayout({
                    newReactiveText
                        .SetDefaultText("hello world")
                        .SetStyleName("default-txt")
                        .addComponent(),
                    newHtmlText
                        .SetHtmlLabel("span")
                        .SetTextColor(COLOR_WHITE)
                        .SetText("Hai Developer!")
                        .SetTextSize(TEXT_SIZE_MEDIUM)
                        .SetFontWeight(TEXT_WEIGHT_BOLD)
                        .SetFontFamily(FONT_JETBRAINS_MONO)
                        .addComponent()
                },[&newReactiveText , &NewButton]()->Gtk::Widget*{
                    NewButton
                        .SetButtonLabel("Click me")
                        .SetButtonAdaption(BUTTON_ADAPTION_WIDTH_FALSE, 
                            BUTTON_ADAPTION_HEIGHT_FALSE)
                            .SetButtonAlign(BUTTON_ALIGN_CENTER)
                            .SetButtonStyle("default-button")
                            .SetButtonMargin(10)
                            .UserClick(true)
                            .Click([&newReactiveText]{
                                newReactiveText.ReactiveText("hai");
                            });
                            return NewButton.addComponent();
                });
        })
        .start();
}
```
<p>В настоящее время поддержка ограничена. Мы над этим работаем! Если вы хотите внести свой вклад в разработку или обслуживание, свяжитесь со мной по адресу xingxixi335@gmail.com или отправьте запросы на включение напрямую. Любой вклад очень ценится! Возможно, я не идеален в этом, поэтому руководство опытных открытых разработчиков в помощи с документацией было бы замечательно.</p>

<h3>Скриншоты из разработки (Это заняло некоторое время!)</h3>
<div class="picture-box">
    <img class="picture-style" src="/github-picture/image1.png" alt="Скриншот разработки">
    <img class="picture-style" src="/github-picture/image2.png" alt="Скриншот разработки">
    <img class="picture-style" src="/github-picture/image3.png" alt="Скриншот разработки">
    <img class="picture-style" src="/github-picture/image4.png" alt="Скриншот разработки">
    <img class="picture-style" src="/github-picture/image5.png" alt="Скриншот разработки">
    <img class="picture-style" src="/github-picture/image6.png" alt="Скриншот разработки">
</div>

<h2>Давайте поговорим о недостатках фреймворка</h2>
<ul>
    <li>Не изменяйте исходный код случайным образом - Вы не представляете, насколько сложным может быть жизненный цикл окна Gtkmm.</li>
    <li>Если вы найдете какие-либо орфографические ошибки в моем API, пожалуйста, сообщите мне через проблемы или запросы на включение - это огромный вклад!</li>
    <li>Не удаляйте компоненты произвольно - это может привести к сбою вашего приложения!!!</li>
</ul>
<p>Заранее спасибо за сообщение о любых проблемах, с которыми вы столкнетесь при использовании фреймворка. Активное сообщение об ошибках очень ценится!</p>

<h2>Мое видение</h2>
<ul>
    <li>Мне надоело, что программное обеспечение для рабочего стола Linux глючное - методы ввода, такие как Fcitx5, действуют странно, различные ошибки отображения, плохая адаптация (глядя на тебя, NVIDIA - мы все знаем "so NVIDIA, fu** you" 😂). Хотя на видеокарту возлагается большая часть вины, программное обеспечение на основе React часто имеет высокое использование памяти, плохую базовую адаптацию, проблемы с отображением или сбои при записи экрана Wayland/удаленном рабочем столе. На старом оборудовании оно может зависнуть или вообще не загрузиться. Это причина первая.</li>
    <li>Причина вторая: Я хочу популяризировать Linux, сделать его таким же распространенным, как macOS и Windows, а не ограничиваться серверами, техническими энтузиастами или студентами компьютерных наук, изучающими Linux-серверы. Если однажды журналы серверов Amazon будут в основном на Linux, я проснусь со смехом! Нехватка пользователей Linux в основном проистекает из отсутствия повседневного программного обеспечения. Многие клиенты Windows/macOS имеют досуговое или профессиональное офисное программное обеспечение, которое либо не существует для Linux, либо имеет ужасную адаптацию. Естественно, обычные пользователи не переключатся. Gtkmm является открытым исходным кодом, но его трудно использовать; Qt не бесплатен. Адаптации JavaScript влияют на производительность. Имея мало пользователей Linux, крупные компании не считают его достойным поддержки. Нам нужна хорошая структура, чтобы возродить рабочий стол Linux. Это может показаться невозможным, но давайте попробуем!</li>
</ul>

<h2>Об авторе - kwzDev</h2>
<h3>Я могу казаться загадочным 😂</h3>
<p>Я довольно неуспешный ученик средней школы с ужасными оценками. Меня не интересуют никакие школьные предметы, потому что они кажутся мне бесполезными. В азиатском обществе я чувствую, что степень не гарантирует лучшую работу - только возможность собеседования. Многие выпускники по программированию становятся курьерами, даже не получив работу.</p>

<h4>Больше обо мне 😅</h4>
<p>Мне очень не нравится учиться. Я не знаю почему - я просто не могу втянуться. Я начал программировать, потому что это было весело. Мое первое знакомство было с HTML на платформах коротких видео. Хотя это всего лишь язык разметки, немедленная обратная связь в браузере взволновала меня, поэтому я начал изучать программирование. Мне не нравится изучать основы... ладно, хорошо, я действительно изучал основы Python 😂.</p>

<h4>Какие языки программирования я затронул? 🌚</h4>
<ul>
    <li>Python - Мой первый логический язык программирования и единственный, основы которого я изучал. Я использовал его для веб-скрапинга и телеграм-ботов, а также Flask для моего первого опыта работы с бэкендом.</li>
    <li>C# - Мой второй пакетно-зависимый язык. Я не изучал никаких основ, но использовал ASP.NET Core для бэкенд-программ, хотя только локальный CRUD с SQLite, поскольку у меня не было значимого контента API.</li>
    <li>Java - Мой третий пакетно-зависимый язык. Не изучая основ, я использовал документацию и запросы к ИИ, чтобы изучить Spring Boot и разработку под Android. В конце концов я отказался от него из-за излишней сложности! Это тошнотворно. Я лично ненавижу эту философию дизайна. Я думаю, что простые классы запросов, конфигурация служб, ограничение скорости по IP, логирование и аутентификация JWT достаточно, без добавления так называемого корпоративного дизайна к уже удобным инструментам!</li>
    <li>C++ - Мой любимый язык программирования. Я не изучал обширных основ, просто понял указатели и простые концепции ООП (инкапсуляция, наследование, полиморфизм). Я не посещал курсы - всего 7 недель самостоятельного изучения на данный момент.</li>
</ul>

<h5>Я не считаю себя очень опытным, поскольку большая часть моего кода довольно проста. За исключением C++, я не углублялся глубоко, поэтому я не так силен. Если я построю официальный веб-сайт в будущем, я буду использовать фреймворк Drogon Антао, а не C# или Java. Почему? Мне просто не нравятся языки программирования, которые скрывают слишком много деталей. Если вы дочитали до этого места, спасибо, что хотите узнать больше обо мне!</h5>

<h1>Лицензия</h1>
<p>Этот проект лицензирован под <strong>GNU General Public License v3.0 (GPL-3.0)</strong>.</p>
<p>Подробности можно найти в файле <a href="LICENSE">LICENSE</a>.</p>

<h2>License</h2>
<p>This project is licensed under the <strong>GNU General Public License v3.0 (GPL-3.0)</strong>.</p>
<p>See the <a href="LICENSE">LICENSE</a> file for details.</p>

<h1 id="zh-cn">zh-CN</h1>

# Visual BeautifUL UI Freamwork 2026 Rebirth edition _ KwzDeve 


<img class="logo-pictuer" src="/github-picture/logo/logo.png" alt="logo">

<h3>多语言 / Languages </h3>
<a href="#en">English</a>
<a href="#ru-RU">Русский</a>
<a href="#zh-cn">中文</a>

<h2>先说重点</h2>
<p>Visual BeautifUL UI 基于 GTkmm 4.0 封装的全新 API , 我之前的版本
    Vbui 不能说失败只能说 嗯 比较难用我们举例一下几点 我本人都想吐槽
    <ul>
        <li>😵‍💫参数不明天知道啊 text("hello" , 20 , 20 ,false)的函数式调用我也是想笑,当时一心模仿Flutter的语法却忘记我们真的想要的是简单易用的框架</li>
        <li>🤮扩展性十分差,比如我们需要多函数协作而Vbui v1.0支持十分的差当我们想删除某些代码时候会发现),20,false)这种括号会让我们十分的头大不知道从何删除</li>
        <li>🤔维护性也非常垃圾同上一点删除难,不仅删除难找参数也难并且编码的时候我们无法清晰的知道我们下一句要用什么参数这让我们用起来十分的难受而且后期不管是团队还是个人开发者都比较感觉恶心
            这在Visual BeautifUL UI Freamwork 2026 当中得到了解决我使用了连接式调用
        </li>
    </ul> 
</p>
<h2>那新版得到了解决吗?</h2>
<p>
    是的我在新版中使用了连接式调用函数 RAII 写法不再使用单一函数 调用参数变得明确不再是黑盒子参数,
    虽然说简洁性不在特别好,但是那也只是命名上的削减在Ide的提示下写起来十分爽快
    <h4>那有保留旧API的什么吗?🤔</h4>
    <p>是的我保留了旧版的一样重要东西! 那就是 std::vector<> 写法让API看起来十分的优雅
    <h4>那重生版加了什么吗?🤔</h4>
    <p>除了API的大更新,我还加入了函数分离协作开发者可以分离函数协作,后期会添加类似JavaScript的FetchAPI来进行前后端交互,已经包管理分类不再是单文件夹所有头文件,文件夹分类后使其变得更加方便和导入记忆
        以及长期维护当然一个人也是比较累的希望可以有更多Linux爱好者可以加入其中共同维护当前是重写的初期可能很多组件并不完整希望大家原谅,在此祝大家新的一年可以更好的提高编码能力!
    </p>
</p>

<h2>新版本快速开始</h2>

```cpp
#include "../src/LayoutComponentController/LayoutBlockComponentController.h"
#include "../src/ApplicationController/Application.h"
#include "../src/ButtonComponentController/Button.h"
#include "../src/TextComponent/ReactiveText.h"
#include "../src/TextComponent/HtmlText.h"
#include "gtkmm/widget.h"

using namespace std;
using namespace Gtk;
using namespace VisualUI;

int main () {
    VisualUI::Application()
        .SetAppID("myapp")
        .SetAppName("myapp")
        .SetAppTitle("hello world")
        .SetWindowSize(600, 400)
        .CreateContent([]() -> Widget*{
            BlockLayoutColumns blocklayout;
            MAKE_COMPONENT(ReactiveComponentText, newReactiveText);
            MAKE_COMPONENT(ButtonComponent, NewButton);
            MAKE_COMPONENT(HtmlText, newHtmlText)
            return blocklayout
                .SetLayoutHeight(200)
                .SetLayoutWidth(200)
                .CreateBlockLayout({
                    newReactiveText
                        .SetDefaultText("hello world")
                        .SetStyleName("default-txt")
                        .addComponent(),
                    newHtmlText
                        .SetHtmlLabel("span")
                        .SetTextColor(COLOR_WHITE)
                        .SetText("Hai Developer!")
                        .SetTextSize(TEXT_SIZE_MEDIUM)
                        .SetFontWeight(TEXT_WEIGHT_BOLD)
                        .SetFontFamily(FONT_JETBRAINS_MONO)
                        .addComponent()
                },[&newReactiveText , &NewButton]()->Gtk::Widget*{
                    NewButton
                        .SetButtonLabel("Click me")
                        .SetButtonAdaption(BUTTON_ADAPTION_WIDTH_FALSE, 
                            BUTTON_ADAPTION_HEIGHT_FALSE)
                            .SetButtonAlign(BUTTON_ALIGN_CENTER)
                            .SetButtonStyle("default-button")
                            .SetButtonMargin(10)
                            .UserClick(true)
                            .Click([&newReactiveText]{
                                newReactiveText.ReactiveText("hai");
                            });
                            return NewButton.addComponent();
                });
        })
        .start();
}
```
<p>
    目前支持较少 等待完善吧! 如果想加入完善开发或者维护 可以联系 xingxixi335@gmail.com 这是我的邮箱或者直接提交请求这都是最大的贡献我做的可能不是很好希望可以更多开源大佬指点帮助我完成注释
</p>

<h3>下面是我开发时候的截图只能说耗时比较久的</h3>
<div class="picture-box">
<img class="picture-style" src="/github-picture/image1.png" alt="开发图">
<img class="picture-style" src="/github-picture/image2.png" alt="开发图">
<img class="picture-style" src="/github-picture/image3.png" alt="开发图">
<img class="picture-style" src="/github-picture/image4.png" alt="开发图">
<img class="picture-style" src="/github-picture/image5.png" alt="开发图">
<img class="picture-style" src="/github-picture/image6.png" alt="开发图">
</div>
<h2>先讲一下这个框架的坑</h2>
<p>
    <ul>
        <li>不要随意改变源码因为你不知道Gtkmm的窗口生命周期有多么恶心</li>
        <li>如果我的API中有任何单词拼错请在我的请求当中告知我这是伟大的贡献!</li>
        <li>不要随意删除组件到时候软件会崩溃!!!</li>
    </ul>
    <span>在此感谢大家的提醒如果在使用中遇到问题积极报告我这是很不错的做法</span>
</p>
<h2>关于我的愿景</h2>
<p>
    <ul>
        <li>我看不下去Linux桌面的软件各种卡输入法如Fcitx5又或是,各种显示BUG适配垃圾比如说英伟达都知道那句 "so NVIDIA fu** you" 吧😂
            虽然这显卡背锅多但是在某些React写的软件中内存占用多 , 底层适配差以及显示适配又或者Wayland的录屏与远程桌面爱崩溃在某些老机型
            卡死或者无法进入这是其一 
        </li>
        <li>其二是我想普及Linux让他变得和MacOS,Windows一样常见而不是寥寥无几几乎都是服务器用或者是技术极客又或是计算机大学生学习Linux服务器
            如果有一天亚马逊服务器日志一大半都是Linux请头那我真的要从梦中笑醒,而Linux用户稀少原因最主要是日常软件的缺失很多Windows,MacOS客户端具备的日常消遣软件或者是专业办公软件在Linux适配不是很垃圾就是没有自然没有普通用户愿意使用而Gtkmm和Qt一个开源难用一个不开源得花钱而Js适配影响体验很差Linux用户少大厂
            ,感觉不值得自然放弃做Linux客户端我们得做个好用的框架让Linux桌面复兴虽然感觉我不太可能但是赌一把吧</li>
    </ul>

</p>
<h2>关于作者 kwzDeve</h2>
<div>
    <h3>我可能显得很神秘😂</h3>
    <p>
        我是一个很失败的初中生我学习成绩十分的差我对学校的任何科目都不感兴趣因为在我看来那很无用在整个亚洲社会我感觉学历并不能得到更好的工作只是得到面试的机会大部分学完编程的大学生都去送外卖了连加入工作机会都没有
        <h4>那再说说我吧😅</h4>
        <p>我这个人十分讨厌学习我不知道为什么我就是学不进去我学编程是因为我感觉这个能让我感觉到好玩吧我第一次学习编程是在短视频平台看见了HTML编程虽然只是标记语言但是那种写完浏览器就立马给予反馈让我很兴奋我便开始学习编程我学习不爱学习基础的哦好吧Python学习了😂</p>
        <h4>我接触了那些编程语言呢🌚</h4>
        <ul>
            <li>Python 这是我最早接触的逻辑性编程语言 也是唯一学习了基础的 我第一次用他写了爬虫以及 电报的机器人 Flask后端我的第一次学习后端</li>
            <li>C# 这是我第二接触的包依赖编程语言 并未学习任何基础我就用 AspNetCore 编写 后端程序 虽然只是 Sqlite本地 CRUD因为我并没有任何值得API分享的内容</li>
            <li>Java 这是我第三接触的包依赖编程语言 并未学习任何基础 我通过文档 以及 AI 提问学习 一次次 ide爆红学习了 SpringBoot,Android开发我后来放弃他的原因十分简单过度设计!十分的恶心我个人表示讨厌这种设计理念我觉得只需要简单的查询类和服务配置与IP限速日志和JWT认证即可没必要再已有的易用工具上加上所谓的企业设计!</li>
            <li>C++ 这是我最爱的编程语言我并未学习过多基础 我只是理解了指针与简单的 OOP 编程理念 封装,继承,多态 这三大概念 并未听课报班到现在我就学了7周</li>
        </ul>
        <h5>我自我感觉我不是很厉害毕竟代码都挺简单的除了C++都没有深入所以不算太强我以后如果要做官网我会使用安涛前辈的Drogon框架做不会使用Csharp和Java别问我为什么问就是不太喜欢隐藏细节的编程语言如果你看到这里那我很感激你愿意了解我!</h5>

<h1>许可证</h1>

本项目采用 **GNU General Public License v3.0 (GPL-3.0)** 开源许可证。

详情请查看 [LICENSE](LICENSE) 文件。

<h2>License</h2>

This project is licensed under the **GNU General Public License v3.0 (GPL-3.0)**.

See the [LICENSE](LICENSE) file for details.
    </p>
</div>

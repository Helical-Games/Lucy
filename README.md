Lucy is lightweight UI & Input framework for projects created in Unreal Engine 4. 
* Based on UMG, written mostly in blueprints. It's free to use, even commercially.
* It allows for compositing UI from fully reusable widgets called composites. Define widget style and logic once, use it hundred times! Or define logic once and set different appearance for every widget instance.
* In clean UMG (without any own scripts) you have to script every element (like button, text or slider) individually. It means lots of copy-pasting scripts responsible for input, localization, styling, setting and restoring state. Everything. Of course many developers close part of those scripts in reusable functions and apply them at every element. My approach is to close entire functionality of element or element group in separate widget file, then simply put this widget in UI panel and fill up parameters. Element added in UMG's Designer tab works out of the box. There's no need to script anything except your custom game logic.
* Appearances of widgets placed in panels refresh automatically after change - which isn't possible in pure UMG.
* And I'm adding a lot of common functions for managing UI panels and input (not only UI related).

### Take a look!
This is entire script for Pause Menu, as simple as it always should be.

![Alt](http://i.imgur.com/Y0VAygC.png "Pause Menu")

You don't need to produce spaghetti blueprint for every UI element. Prepare it quickly by setting params.

![ALT](http://i.imgur.com/2e31OQV.png "Params")

### What's inside?
* Typical UI composites like Text Button, Interaction Hint, Labeled Slider, etc. Every composite automatically updates its default state based on instance values.
* UI Manager takes care of creating and switching panels, opening panels in hierarchy, handling input, basic navigation, activating chosen widget in panel, receiving input from active widget. So you don't have to script basic widget actions in your panels. Focus on designing it and scripting custom and advanced functions.
* Samples of Main/Options menus simplifies creating your own menus, i.e. Video Menu allows you to set common graphics options. Just customize it to your needs. Or just download it, don't change a thing and enjoy basic menus working in your cooked build.
* Input Manager provides basic functionalities: setting various inputs for single action, activating interactions, detecting input device and automatically updating displayed icon and key of interaction.
* You don't have to reinvent the wheel when you're starting work on UI. I already did it. Partially ;)
* 
### All links you need
* [Wiki: Getting Started](https://github.com/kjustynski/Lucy/wiki/Getting-Started)
* [Trello Board](https://trello.com/b/p4HZ0RuB/lucy)
* [Twitter](https://twitter.com/kjustynski)

### Third-party 
* Few blueprint functions from [LE Extended Standard Library](https://www.unrealengine.com/marketplace/low-entry-extended-standard-library)
* Controller icons created by [Xelu](http://opengameart.org/content/free-keyboard-and-controllers-prompts-pack).
* Miscellaneous icons from  [To [icon]](http://www.toicon.com/about) project.
* Chopin's Nocturne performed by Frank Levy. More at [Musopen.org](https://musopen.org/music/245/frederic-chopin/nocturnes-op-9/).


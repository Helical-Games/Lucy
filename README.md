Lucy is lightweight UI & Input framework for projects created in Unreal Engine 4. 
* Based on UMG, blueprint only. It's free to use, even commercially.
* It takes different approach on compositing user interfaces in UE4. In clean UMG (without any own scripts) you have to script every element (like button, text or slider) individually. It means lots of copy-pasting scripts responsible for input, localization, styling, setting and restoring state. Everything. Of course many developers close part of those scripts in reusable functions and apply them at every element. My approach is to close entire functionality of element or element group in separate widget file, then simply put this widget in UI panel and fill up parameters. Element added in UMG's Designer tab works out of the box. 
* And I added to it easy way to manage UI panels and input (not only UI related) in game :)

### What's inside?
* Input Manager provides basic functionalities: setting various inputs for single action, activating interactions, detecting input device and automatically updating displayed icon and key of interaction.
* UI Manager takes care of creating and switching panels, opening panels in hierarchy, handling input, basic navigation, activating chosen widget in panel, receiving input from active widget. So you don't have to script basic widget actions in your panels. Focus on designing it and scripting custom and advanced functions. 
* Typical UI composites are UMG widgets provided with script which handles basic logic and input for you. Every composite automatically updates its default state based on instance value.
* Samples of Main/Options menus simplifies creating your own menus, i.e. Video Menu allows you to set common graphics options. Just customize it to your needs. Or just download it, don't change a thing and enjoy basic menus working in your cooked build. It's useful for playtesting prototypes.
* You don't have to reinvent the wheel when you're starting work on UI. I already did it. Partially ;)

### Take a look!
This is entire script for Pause Menu, as simple as it always should be.

![Alt](http://i.imgur.com/Y0VAygC.png "Pause Menu")

You don't need to produce spaghetti blueprint for every Text or Slider element. Prepare it quickly by setting params.

![ALT](https://i.imgur.com/O1xuOXU.png "Params")

Entire UI could be constructed by using "composites", simple UI elements with script handling input, localization and common operations.

![ALT](https://i.imgur.com/p6jc5MH.png "Label + Slider")

### All links you need
* [Wiki: Getting Started](https://github.com/kjustynski/Lucy/wiki/Getting-Started)
* [Trello Board](https://trello.com/b/p4HZ0RuB/lucy)
* [Twitter](https://twitter.com/kjustynski)

### Dependencies
* Free Blueprint plug-in [LE Extended Standard Library](https://www.unrealengine.com/marketplace/low-entry-extended-standard-library)

### Third-party assets used in sample project
* Controller icons created by [Xelu](http://opengameart.org/content/free-keyboard-and-controllers-prompts-pack).
* Miscellaneous icons from  [To [icon]](http://www.toicon.com/about) project.
* Chopin's Nocturne performed by Frank Levy. More at [Musopen.org](https://musopen.org/music/245/frederic-chopin/nocturnes-op-9/).


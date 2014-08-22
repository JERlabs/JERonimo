#ifndef _APP_H_
#define _APP_H_

#include <string>

#include "Declarations.h"
#include "ControlInterfaces/Loadable.h"
#include "ControlInterfaces/Runnable.h"

namespace jer
{
    using std::string;
    
	class App: public Loadable, public Runnable
	{
	private:
		static App app;   /// SDL Application for the whole program
	
	public:
		static App& GetApp() {return app;};
		
	private:
		Runnable *mainApp;
		Uint32 initFlags;
        string winTitle;
	
	public:
		virtual ~App() {if(isLoaded()) unload();};
		App(): mainApp(NULL), initFlags(SDL_INIT_EVERYTHING) {};
		
	public:
		void setApp(Runnable * const a) {mainApp = a;};
		Runnable * const getApp() const {return mainApp;};
		void initAll() {initFlags = SDL_INIT_EVERYTHING;};
		void initNone() {initFlags = 0;};
        void setWindowTitle(const string &t) {winTitle = t;};
        const string &getTitle() const {return winTitle;};
		
	public:
		const SUCCESS load() override;
		const SUCCESS unload() override;
		const SUCCESS run() override;
        void stop() override {if(mainApp) mainApp->stop();};
		
	private:
		const SUCCESS loadSubSystem(const Uint32 flags);
		
	public:
		const SUCCESS loadTimer() {return loadSubSystem(SDL_INIT_TIMER);};
		const SUCCESS loadAudio() {return loadSubSystem(SDL_INIT_AUDIO);};
		const SUCCESS loadVideo() {return loadSubSystem(SDL_INIT_VIDEO);};
		const SUCCESS loadJoystick() {return loadSubSystem(SDL_INIT_JOYSTICK);};
		const SUCCESS loadHaptic() {return loadSubSystem(SDL_INIT_HAPTIC);};
		const SUCCESS loadGameController() {return loadSubSystem(SDL_INIT_GAMECONTROLLER);};
		const SUCCESS loadEvents() {return loadSubSystem(SDL_INIT_EVENTS);};
	};
}


#endif /*_APP_H_*/
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// floor
	floor.x = 8;
	floor.y = 376;
	floor.w = 848;
	floor.h = 64;

	// walls
	walls.x = 120;
	walls.y = 128;
	walls.w = 671;
	walls.h = 199;

	// roof
	roof.x = 91;
	roof.y = 8;
	roof.w = 765;
	roof.h = 48;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading honda scene");
	graphics = App->textures->Load("honda_stage2.png");
	App->player->Enable();
	App->audio->PlayMusic("honda.ogg", 2.0f);
	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");
	App->textures->Unload(graphics);
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, -40, 160, &floor, 4.0F);//floor
	App->renderer->Blit(graphics, -10, 0, &walls, 4.0f); //walls
	App->renderer->Blit(graphics, -60, 0, &roof, 4.0F);//roof
	
	return UPDATE_CONTINUE;
}
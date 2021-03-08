#include "GameLoop.h"

GameLoop::GameLoop(int height, int width)
{
	/*GameWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(GameWindow, -1, 0);*/
	/*player = new Player();
	player->SetPosition(Vector2(300, 300));
	activeGame = true;
	bullets.reserve(100);
	rocks.reserve(50);
	
	for (int i = 0; i < 4; i++)
	{
		int rand = std::rand()%600;
		if (rand > 200 && rand < 400)
			rand += 200;
		AstroidRock* rock = new AstroidRock(3, Vector2(rand, rand));
		rocks.push_back(rock);
	}
	HookEvent(player);*/
}

GameLoop::~GameLoop()
{
	/*UnhookEvent(player);
	delete player;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(GameWindow);*/
}

//void GameLoop::UpdateLoop()
//{
//	double t = 0.0;
//	double dt = 1.0 / 60.0;
//
//	steady_clock::time_point currentTime = steady_clock::now();
//	double timeChecker = 0;
//	double accumulator = 0.0;
//	while (activeGame)
//	{
//		steady_clock::time_point newTime = steady_clock::now();
//		double frametime = (duration_cast<duration<double>>(newTime - currentTime)).count();
//		currentTime = newTime;
//		accumulator += frametime;
//		while (accumulator >= dt)
//		{
//			FixedUpdate(dt);
//			t += dt;
//			accumulator -= dt;
//		}
//		RenderUpdate();
//	}
//}

void GameLoop::GatherPlayerInput(double dt)
{
	/*SDL_PumpEvents();
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_LEFT])
		player->Rotate(false);
	if (state[SDL_SCANCODE_RIGHT])
		player->Rotate(true);
	if (state[SDL_SCANCODE_UP])
		player->ThrustForward();
	else if (!state[SDL_SCANCODE_UP])
		player->Deaccelerate(); 
	if (state[SDL_SCANCODE_SPACE])
		player->Shoot();
	if (state[SDL_SCANCODE_ESCAPE])
		activeGame = false;	*/
}

void GameLoop::FixedUpdate(double dt)
{
	/*GatherPlayerInput(dt);
	player->UpdatePlayer(dt);
	int removeBulletAtIndex = -1;
	for (std::size_t i = 0; i < bullets.size(); ++i) {
		bullets[i]->UpdateBullet(dt);
		if (bullets[i]->GetLifeTime() <= 0)
			removeBulletAtIndex = i;
	}
	for (std::size_t i = 0; i < rocks.size(); ++i) {
		rocks[i]->UpdateAstroid();
	}
	if (removeBulletAtIndex != -1) {
		delete bullets[removeBulletAtIndex];
		bullets.erase(bullets.begin() + removeBulletAtIndex);
	}
	CheckCollisions();*/
}

void GameLoop::OnBulletFired()
{
	/*printf_s("BulletFiredEvent received.\n");
	Bullet* bullet = new Bullet();
	bullets.push_back(bullet);
	bullet->SetPosition(player->GetPosition());
	bullet->GetRigidbody()->AddForce(player->GetDirection() * 7.5);*/
}

void GameLoop::RenderUpdate()
{
	/*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	player->RenderPlayer(renderer);

	for (std::size_t i = 0; i < bullets.size(); ++i) {
		bullets[i]->RenderBullet(renderer);
	}
	for (std::size_t i = 0; i < rocks.size(); ++i) {
		rocks[i]->Render(renderer);
	}

	SDL_RenderPresent(renderer);*/
}

void GameLoop::CheckCollisions() 
{
	//int removeIndex = -1;
	//int bulletIndex = -1;
	//for (std::size_t i = 0; i < rocks.size(); ++i) {
	//	for (std::size_t j = 0; j < bullets.size(); ++j) {
	//		if (rocks[i]->GetCollider()->Overlaping(*(bullets[j]->GetCollider())))
	//		{
	//			//bullet hit astroid collider
	//			removeIndex = i;
	//			bulletIndex = j;
	//			break;
	//		}
	//	}
	//	if (rocks[i]->GetCollider()->Overlaping(*(player->GetCollider())))
	//	{
	//		//player hit astroid collider
	//		activeGame = false;
	//		break;
	//	}
	//}

	//if (removeIndex != -1) 
	//{
	//	//sum crusaded shit, look it up plz
	//	delete rocks[removeIndex];
	//	rocks.erase(rocks.begin() + removeIndex);
	//	delete bullets[bulletIndex];
	//	bullets.erase(bullets.begin() + bulletIndex);
	//}
}
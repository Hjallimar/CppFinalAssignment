#include "IState.h"

GameState::~GameState()
{
	delete player;
}

void GameState::Init(StateMachine* newHead)
{
	head = newHead;
	player = new Player();
	bullets.reserve(100);
	rocks.reserve(50);
}

void GameState::Enter()
{
	std::cout << "Enter GameState" << std::endl;
	player->SetPosition(Vector2(300, 300));

	for (int i = 0; i < 4; i++)
	{
		int rand = std::rand() % 600;
		if (rand > 200 && rand < 400)
			rand += 200;
		int rand2 = std::rand() % 600;
		if (rand2 > 200 && rand2 < 400)
			rand2 += 200;
		AstroidRock* rock = new AstroidRock(3, Vector2(rand, rand2));
		rocks.push_back(rock);
	}
	HookEvent(player);
}

void GameState::Update(double dt)
{
	GatherPlayerInput();
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
	CheckCollisions();
}

void GameState::Render()
{
	SDL_SetRenderDrawColor(head->renderer, 0, 0, 0, 255);
	SDL_RenderClear(head->renderer);

	SDL_SetRenderDrawColor(head->renderer, 255, 255, 255, 255);
	player->RenderPlayer(head->renderer);

	for (std::size_t i = 0; i < bullets.size(); ++i) {
		bullets[i]->RenderBullet(head->renderer);
	}
	for (std::size_t i = 0; i < rocks.size(); ++i) {
		rocks[i]->Render(head->renderer);
	}

	SDL_RenderPresent(head->renderer);
}

void GameState::Exit()
{
	std::cout << "Exit GameState" << std::endl;
	UnhookEvent(player);
	player->GetRigidbody()->Nullify();
	rocks.clear();
	bullets.clear();
}

void GameState::GatherPlayerInput()
{
	SDL_PumpEvents();
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
		head->SwitchState(0);
}

void GameState::OnBulletFired()
{
	Bullet* bullet = new Bullet();
	bullets.push_back(bullet);
	bullet->SetPosition(player->GetPosition());
	bullet->GetRigidbody()->AddForce(player->GetDirection() * 7.5);
}

void GameState::CheckCollisions()
{
	int removeIndex = -1;
	int bulletIndex = -1;
	for (std::size_t i = 0; i < rocks.size(); ++i) {
		for (std::size_t j = 0; j < bullets.size(); ++j) {
			if (rocks[i]->GetCollider()->Overlaping(*(bullets[j]->GetCollider())))
			{
				//bullet hit astroid collider
				removeIndex = i;
				bulletIndex = j;
				break;
			}
		}
		if (rocks[i]->GetCollider()->Overlaping(*(player->GetCollider())))
		{
			//player hit astroid collider
			head->SwitchState(0);
			break;
		}
	}

	if (removeIndex != -1)
	{
		//sum crusaded shit, look it up plz
		rocks[removeIndex]->TrySplit(&rocks);
		delete rocks[removeIndex];
		rocks.erase(rocks.begin() + removeIndex);
		delete bullets[bulletIndex];
		bullets.erase(bullets.begin() + bulletIndex);
	}
}

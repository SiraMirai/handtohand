#pragma once

namespace PickpocketReplace
{
	inline static std::array<std::uint8_t, 1> SkillIndexReplace{ 0x0D };

	void static Install()
	{

		//1.5.97(SSE) & 1.4.15(VR)
		static REL::Relocation<std::uintptr_t> hook_LockPick{ REL::ID(51088), 0x4E };
		static REL::Relocation<std::uintptr_t> hook_LockPickBreak{ REL::ID(51093), 0x234 };

		static REL::Relocation<std::uintptr_t> hook_LockpickMenuSkillLevel{ REL::ID(51084), 0x73 };
		static REL::Relocation<std::uintptr_t> hook_LockpickMenuXPProgress{ REL::ID(51084), 0xCA };


		REL::safe_write<std::uint8_t>(hook_LockPick.address(), SkillIndexReplace);
		REL::safe_write<std::uint8_t>(hook_LockPickBreak.address(), SkillIndexReplace);
		REL::safe_write<std::uint8_t>(hook_LockpickMenuSkillLevel.address(), SkillIndexReplace);
		REL::safe_write<std::uint8_t>(hook_LockpickMenuXPProgress.address(), SkillIndexReplace);
	}
}


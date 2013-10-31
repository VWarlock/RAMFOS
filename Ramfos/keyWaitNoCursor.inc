; Тут ошибка, курсор всётаки может промелькнуть

keyWaitNoCursor:call	j_keyCheck
		jnz	j_keyWait
		jmp	keyWaitNoCursor
scene->obj[1] = obj(CYLINDER,						// type
				0.01,								// radius
				500.0,								// height
				vecp(0.0, 0.0, -50.0), 				// position
				vecp(0.0, 0.0, -1.0), 				// direction
				vecp(0.0, 0.0, 0.0),				// emission
				vecp(0.0, 0.0, 5.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0.5,								// Angle
				0,									// Cut direction
				0, 0, 0,							// Box rect
				DIFF);								// material


scene->obj[2] = obj(CYLINDER,						// type
				0.01,								// radius
				500.0,								// height
				vecp(0.0, 0.0, -50.0), 				// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(0.0, 0.0, 0.0),				// emission
				vecp(0.0, 5.0, 0.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0.5,								// Angle
				0,									// Cut direction
				0, 0, 0,							// Box rect
				DIFF);

scene->obj[3] = obj(CYLINDER,						// type
				0.01,								// radius
				500.0,								// height
				vecp(0.0, 0.0, -50.0), 				// position
				vecp(1.0, 0.0, 0.0), 				// direction
				vecp(0.0, 0.0, 0.0),				// emission
				vecp(5.0, 0.0, 0.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0.5,								// Angle
				0,									// Cut direction
				0, 0, 0,							// Box rect
				DIFF);

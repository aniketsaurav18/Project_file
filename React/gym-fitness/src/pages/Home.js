import React, { useState } from "react";
import { Box } from "@mui/material";
import Exercise from "../components/Exercise";
import SearchExercises from "../components/SearchExercises";
import HeroBanner from "../components/HeroBanner";
import BodyPart from "../components/BodyPart";

const Home = () => {
  const [BodyPart, setBodyPart] = useState("all");
  const [exercises, setExercises] = useState([]);
  return (
    <Box>
      <HeroBanner />
      <SearchExercises
        setExercises={setExercises}
        bodyPart={BodyPart}
        setBodyPart={setBodyPart}
      />
      <Exercise
        setExercises={setExercises}
        bodyPart={BodyPart}
        exercises={exercises}
      />
    </Box>
  );
};

export default Home;
